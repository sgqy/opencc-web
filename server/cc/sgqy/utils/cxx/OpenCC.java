package cc.sgqy.utils.cxx;

public class OpenCC {
    static {
        System.loadLibrary("opencc4j");
    }

    private native long new_obj(String conf);
    private native long del_obj(long ptr);
    private native String conv_text(long ptr, String text);

    private long ptr = 0;

    private OpenCC(String conf) throws RuntimeException {
        this.ptr = new_obj(conf);
        if (this.ptr == 0) {
            throw new RuntimeException(String.format("opencc4j/java: cannot create converter from %s.", conf));
        }
    }
    public static OpenCC getInstance(String conf) {
        return new OpenCC(conf);
    }
    public void exit() {
        this.ptr = del_obj(this.ptr);
    }
    public String conv(String text) {
        if (this.ptr <= 0) {
            throw new RuntimeException("opencc4j/java: instance destroyed.");
        }
        return conv_text(this.ptr, text);
    }
}
