package android.serialport.api;

/**
 * @author Administrator
 *         Date 2017/4/26
 */
public class SerialUtils {
    static {
        System.loadLibrary("seriport");
    }
    public static native void initPort();
}
