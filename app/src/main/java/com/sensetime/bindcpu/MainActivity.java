package com.sensetime.bindcpu;

import android.support.v7.app.AppCompatActivity;
import android.os.Bundle;
import android.util.Log;
import android.widget.TextView;

public class MainActivity extends AppCompatActivity {

    @Override
    protected void onCreate(Bundle savedInstanceState) {
        super.onCreate(savedInstanceState);
        setContentView(R.layout.activity_main);

        // Example of a call to a native method
        TextView tv = findViewById(R.id.sample_text);
        tv.setText(BindToCpu.getCores() + "");

        int cores = BindToCpu.getCores();
        Log.d("qhh","cores = " + cores);
        BindToCpu.bindToCpu(0);
    }

}
