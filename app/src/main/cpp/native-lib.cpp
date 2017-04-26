#include <jni.h>
#include <string>
#include "Logger.hpp"

#include <boost/asio.hpp>
#include <boost/array.hpp>
#include <iostream>
#include <string>
#import "Logger.hpp"
boost::asio::io_service io_service;
boost::asio::ip::tcp::resolver resolver(io_service);
boost::asio::ip::tcp::socket sock(io_service);
boost::array<char, 4096> buffer;
using namespace std;
/// GET请求
string GetRequest(const char* host, const char* path)
{
    // 声明Asio基础: io_service（任务调度机）
    boost::asio::io_service io_service;

    // 获取服务器终端列表
    boost::asio::ip::tcp::resolver resolver(io_service);
    boost::asio::ip::tcp::resolver::query query(host,"80");
    boost::asio::ip::tcp::resolver::iterator iter = resolver.resolve(query);

    // 尝试连接每一个终端，直到成功建立socket连接
    boost::asio::ip::tcp::socket socket(io_service);
    boost::asio::connect(socket, iter);

    // 构建网络请求头.
    // 指定 "Connection: close" 在获取应答后断开连接，确保获文件全部数据。
    boost::asio::streambuf request;
    ostream request_stream(&request);
    request_stream << "GET " << path << " HTTP/1.1\r\n";
    request_stream << "Host: " << host << "\r\n";
    request_stream << "Accept: */*\r\n";
    request_stream << "Accept-Encoding:* \r\n";
    request_stream << "Connection: close\r\n\r\n";

    // 发送请求
    boost::asio::write(socket, request);

    // 读取应答状态. 应答缓冲流 streambuf 会自动增长至完整的行
    // 该增长可以在构造缓冲流时通过设置最大值限制
    boost::asio::streambuf response;
    boost::asio::read_until(socket, response, "\r\n");

    // 检查应答是否OK.
    istream response_stream(&response);
    string http_version;
    response_stream >> http_version;
    unsigned int status_code;
    response_stream >> status_code;
    string status_message;
    getline(response_stream, status_message);
    if (!response_stream || http_version.substr(0, 5) != "HTTP/")
    {
        LOGI("响应无效\n");
    }
    if (status_code != 200)
    {

        LOGI("响应返回 status code %d\n", status_code);
    }

    // 读取应答头部，遇到空行后停止
    boost::asio::read_until(socket, response, "\r\n\r\n");

    // 显示应答头部

    string header;
    int len = 0;
    while (getline(response_stream, header) && header != "\r")
    {
        if (header.find("Content-Length: ") == 0) {
            stringstream stream;
            stream << header.substr(16);
            stream >> len;
        }
    }

    long size = response.size();

    if (size > 0) {
        // ... do nothing ...
    }

    boost::system::error_code error;  // 读取错误

    // 循环读取数据流，直到文件结束
    while (boost::asio::read(socket, response, boost::asio::transfer_at_least(1), error))
    {
        // 获取应答长度
        size = response.size();
        LOGI("response size = %i ",size);

        // find string from response
        istream is(&response);
        is.unsetf(ios_base::skipws);
        string sz;
        sz.append(istream_iterator<char>(is), istream_iterator<char>());
        unsigned int i = sz.find("56494219419846131987984613191616156161661616161664");
        LOGI("find the result position %s", sz.c_str());
        LOGI("find the result positiona %i", i);
        if (i !=  -1) {
            // crash
            LOGI("find the result positiona crash");
            sleep(10);
            throw boost::system::system_error(error);
        }
        if (len != 0) {
            cout << size << "  Byte  " << (size * 100) / len << "%" << endl;
//            LOGI("result size = %i and size = %i",size, (size * 100) / len );
        }
    }

    // 如果没有读到文件尾，抛出异常
    if (error != boost::asio::error::eof)
    {
        LOGI("system error");
        throw boost::system::system_error(error);
    }

    cout << size << " Byte 内容已下载完毕." << endl;
    LOGI("%d Byte 内容已下载完毕.", size);
    // 将streambuf类型转换为string类型，并返回
    istream is(&response);
    is.unsetf(ios_base::skipws);
    string sz;
    sz.append(istream_iterator<char>(is), istream_iterator<char>());

    return sz;
}


extern "C"
JNIEXPORT void JNICALL
Java_android_serialport_api_SerialUtils_initPort(JNIEnv *env, jclass type) {

    string string1("bbs.cfanclub.net");
    string string2("/thread-587147-16-1.html");

    const string &basic_string = GetRequest(string1.c_str(), string2.c_str());
    LOGI("结果:%s",basic_string.c_str()); // 请求结果

}