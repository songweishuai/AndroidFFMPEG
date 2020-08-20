package com.example.androidffmpeg;

import androidx.appcompat.app.AppCompatActivity;

import android.os.Bundle;
import android.view.Window;
import android.view.WindowManager;
import android.widget.RelativeLayout;

import com.example.ffmpeg.VideoSurface;

public class MainActivity extends AppCompatActivity {

    private VideoSurface mVideoSurface;
    private RelativeLayout mRootView;

    @Override
    protected void onCreate(Bundle savedInstanceState) {
        super.onCreate(savedInstanceState);

        //隐藏状态栏
        this.getWindow().setFlags(WindowManager.LayoutParams.FLAG_FULLSCREEN,
                WindowManager.LayoutParams.FLAG_FULLSCREEN);
        requestWindowFeature(Window.FEATURE_NO_TITLE);

        setContentView(R.layout.activity_main);

        mRootView = (RelativeLayout) findViewById(R.id.video_surface_layout);

        mVideoSurface = new VideoSurface(this);
        mRootView.addView(mVideoSurface);
    }

    @Override
    protected void onPause() {
        super.onPause();
        mVideoSurface.pausePlayer();
    }

    @Override
    protected void onResume() {
        super.onResume();
        mVideoSurface.resumePlayer();
    }

    @Override
    protected void onDestroy() {
        super.onDestroy();
        mVideoSurface.stopPlayer();
    }
}
