package jin.com.ndkcamera;

import android.app.Activity;
import android.os.Bundle;
import android.serialport.api.SerialUtils;
import android.view.View;
import android.widget.TextView;

public class MainActivity extends Activity {

    // Used to load the 'native-lib' library on application startup.


    private TextView tv;

    @Override
    protected void onCreate(Bundle savedInstanceState) {
        super.onCreate(savedInstanceState);
        setContentView(R.layout.activity_main);


        tv = (TextView) findViewById(R.id.sample_text);
        tv.setText("haode");
    }

    public void button(View view) {
        /*String s = stringFromJNI();
        tv.setText(s);*/
        SerialUtils.initPort();
    }
}
