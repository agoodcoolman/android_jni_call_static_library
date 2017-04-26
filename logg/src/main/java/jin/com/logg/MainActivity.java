package jin.com.logg;

import android.os.Bundle;
import android.serialport.api.SerialUtils;
import android.support.v7.app.AppCompatActivity;
import android.view.View;

public class MainActivity extends AppCompatActivity {

    @Override
    protected void onCreate(Bundle savedInstanceState) {
        super.onCreate(savedInstanceState);
        setContentView(R.layout.activity_main);
    }
    public void button(View view) {
        SerialUtils.initPort();
    }
}
