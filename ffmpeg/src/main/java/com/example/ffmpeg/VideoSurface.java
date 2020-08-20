package com.example.ffmpeg;

import android.content.Context;
import android.util.Log;
import android.view.Surface;
import android.view.SurfaceView;
import android.view.SurfaceHolder;

import androidx.annotation.NonNull;

public class VideoSurface extends SurfaceView implements SurfaceHolder.Callback {
    private static String TAG = "VideoSurface";


    static {
        System.loadLibrary("ffmpeg");
        System.loadLibrary("videosurface");
    }

    public VideoSurface(Context context) {
        super(context);

        Log.i(TAG, "VideoSurface ");

        getHolder().addCallback(this);
    }

    @Override
    public void surfaceChanged(@NonNull SurfaceHolder surfaceHolder, int format, int width, int height) {
        Log.d(TAG, "surfaceChanged format is" + format + ",width is" + width + ",height" + height);
    }

    @Override
    public void surfaceCreated(@NonNull SurfaceHolder surfaceHolder) {
        Log.d(TAG, "surfaceCreated");
        setSurface(surfaceHolder.getSurface());
    }

    @Override
    public void surfaceDestroyed(@NonNull SurfaceHolder surfaceHolder) {
        Log.d(TAG, "surfaceDestroyed");
    }

    public int pausePlayer() {
        return nativePausePlayer();
    }

    public int resumePlayer() {
        return nativeResumePlayer();
    }

    public int stopPlayer() {
        return nativeStopPlayer();
    }

    public native int setSurface(Surface view);

    public native int nativePausePlayer();

    public native int nativeResumePlayer();

    public native int nativeStopPlayer();
}
