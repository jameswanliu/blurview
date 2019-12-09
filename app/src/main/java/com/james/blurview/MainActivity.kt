package com.james.blurview

import android.graphics.Bitmap
import android.graphics.BitmapFactory
import androidx.appcompat.app.AppCompatActivity
import android.os.Bundle
import com.james.blurviewlib.BlurUtil
import kotlinx.android.synthetic.main.activity_main.*

class MainActivity : AppCompatActivity() {

    override fun onCreate(savedInstanceState: Bundle?) {
        super.onCreate(savedInstanceState)
        setContentView(R.layout.activity_main)
        val bitmap = BitmapFactory.decodeResource(resources,R.mipmap.timg)
        iv_blur.setImageBitmap(BlurUtil.blur(bitmap))
    }
}
