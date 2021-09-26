package gullp.androidotv;

import androidx.appcompat.app.AppCompatActivity;

import android.os.Bundle;
import android.os.Handler;
import android.os.Message;
import android.view.WindowManager;
import android.widget.TextView;

public class MainActivity extends AppCompatActivity {

    // Used to load the 'native-lib' library on application startup.
    static {
        System.loadLibrary("native-lib");
    }

    private Handler updateUIHandler = null;

    public final static int MESSAGE_UPDATE_TEXT_CHILD_THREAD = 1;

    @Override
    protected void onCreate(Bundle savedInstanceState) {
        super.onCreate(savedInstanceState);
        setContentView(R.layout.activity_main);

        TextView tv = findViewById(R.id.sample_text);

        if(updateUIHandler == null){
            updateUIHandler = new Handler(){
                @Override
                public void handleMessage(Message msg) {
                    // Means the message is sent from child thread.
                    if(msg.what == MESSAGE_UPDATE_TEXT_CHILD_THREAD)
                    {
                        tv.setText((String)(msg.obj));
                    }
                }
            };
        }

        // Per evitare che lo schermo si spenga e causi un calo delle prestazioni
        getWindow().addFlags(WindowManager.LayoutParams.FLAG_KEEP_SCREEN_ON);

        OTVThread otvThread = new OTVThread(updateUIHandler);
        otvThread.start();

        tv.setText("OTV was successfully launched in background...");
    }

}