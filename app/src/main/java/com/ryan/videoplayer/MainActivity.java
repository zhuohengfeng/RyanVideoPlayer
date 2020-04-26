package com.ryan.videoplayer;

import android.widget.TextView;

import com.ryan.videoplayer.base.BaseActivity;

/**
 * RTMP的视频直播的播放器界面
 */
public class MainActivity extends BaseActivity {

    // Used to load the 'native-lib' library on application startup.
    static {
        System.loadLibrary("native-lib");
    }


    @Override
    protected int getLayoutId() {
        return R.layout.activity_main;
    }

    @Override
    protected void initView() {
        ((TextView)findViewById(R.id.sample_text)).setText(stringFromJNI());
    }

    @Override
    protected void initData() {
        // 请求权限
    }



    /**
     * A native method that is implemented by the 'native-lib' native library,
     * which is packaged with this application.
     */
    public native String stringFromJNI();

}
