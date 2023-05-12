package cc.sgqy;

import cc.sgqy.utils.cxx.OpenCC;

public class Hello {
    public static void main(String[] args) {
        long startTime = System.nanoTime();
        OpenCC s2t = OpenCC.getInstance("s2twp.json");
        OpenCC t2s = OpenCC.getInstance("tw2sp.json");
        for (int i = 0; i <= 200000; ++i) {
            String tw = s2t.conv("你是在用鼠标看视频的吗？");
            String cn = t2s.conv(tw);
            if (i % 10000 == 0) {
                System.out.println(String.format("%d: %s, %s", i, tw, cn));
            }
        }
        s2t.exit();
        t2s.exit();
        long endTime = System.nanoTime();
        long totalTime = endTime - startTime;
        System.out.println((double)totalTime / (1000 * 1000 * 1000));
    }
}