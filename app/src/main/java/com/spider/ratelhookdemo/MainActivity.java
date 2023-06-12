package com.spider.ratelhookdemo;

import androidx.appcompat.app.AppCompatActivity;

import android.os.Bundle;
import android.widget.TextView;

import com.spider.ratelhookdemo.databinding.ActivityMainBinding;

public class MainActivity extends AppCompatActivity {

    // Used to load the 'ratelhookdemo' library on application startup.

    @Override
    protected void onCreate(Bundle savedInstanceState) {
        super.onCreate(savedInstanceState);
    }

    /**
     * A native method that is implemented by the 'ratelhookdemo' native library,
     * which is packaged with this application.
     */
}