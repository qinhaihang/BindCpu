package com.sensetime.bindcpu;

/**
 * @author qinhaihang_vendor
 * @version $Rev$
 * @time 2019/7/19 19:27
 * @des
 * @packgename com.sensetime.bindcpu
 * @updateAuthor $Author$
 * @updateDate $Date$
 * @updateDes
 */
public class BindToCpu {

    // Used to load the 'native-lib' library on application startup.
    static {
        System.loadLibrary("bind_cpu");
    }

    public static native int getCores();

    public static native void bindToCpu(int cpu);

}
