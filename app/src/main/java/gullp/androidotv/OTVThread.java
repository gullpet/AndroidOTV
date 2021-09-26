package gullp.androidotv;

import android.os.Handler;
import android.os.Message;
import android.widget.TextView;

public class OTVThread extends Thread{

    private Handler handler;

    public OTVThread(Handler handler){
        this.handler = handler;
    }

    public void run(){
        // Actual execution of the OTV native code
        //doesn't work because the textview can only be modified by MainActivity
        //resultTextView.setText( runOTV() );
        //runOTV();
        Message toSend = handler.obtainMessage(MainActivity.MESSAGE_UPDATE_TEXT_CHILD_THREAD, runOTV());
        handler.sendMessage(toSend);
    }

    public native String runOTV();
}
