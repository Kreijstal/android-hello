Hello World Android app with JNI
=======

This is a simple "Hello, World" Android app that demonstrates how to use JNI (Java Native Interface) to call native code from an Android app.

Prerequisites
------

To build and run this app, you will need the following:
* Android Studio
* Android SDK
* JDK (Java Development Kit)

Building and running the app

1. Clone the repository:

```bash
git clone https://github.com/Kreijstal/android-hello.git
```
2. Open the project in Android Studio:

```bash
cd android-hello
open -a Android\ Studio .
```
3. Build and run the app:

*In Android Studio, click the "Run" button (the green arrow icon) to build and run the app.
*Alternatively, you can build the app from the command line using Gradle:
```bash
./gradlew installDebug
```
or
```bash
./gradlew assembleDebug
```
How it works
=====

The app consists of a single activity (MainActivity) that displays a "Hello, World!" message on the screen. The message is generated by a native function (hello()) written in C.

The native function is called from the Java code using JNI. The Java code loads the native library (libhello.so) and calls the hello() function using the System.loadLibrary() method and the native keyword.

For example:
```java
public class MainActivity extends AppCompatActivity {
  static {
    System.loadLibrary("kreijstaltest");
  }

  public native String hello();

  @Override
  protected void onCreate(Bundle savedInstanceState) {
    super.onCreate(savedInstanceState);
    setContentView(R.layout.activity_main);

    TextView textView = findViewById(R.id.text_view);
    textView.setText(hello());
  }
}
```
The native code for the hello() function is located in the jni directory. To build the native code, the app uses the CMakeLists.txt file and the Android.mk file, which are located in the jni directory.

For example:

```c++
#include <jni.h>
#include <string.h>

jstring
Java_work_encasa_pendejo_helloworld_MainActivity_hello(JNIEnv* env, jobject thiz)
{
  return (*env)->NewStringUTF(env, "Hello, World!");
}
```
Resources

* [JNI documentation](https://developer.android.com/training/articles/perf-jni)
* [Android NDK documentation](https://developer.android.com/ndk/guides)

