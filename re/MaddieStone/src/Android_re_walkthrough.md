Android RE
 
1.    Step 1: Decompile an Android JADX, Apktool, Bytecode Viewer or Android Studio.
2.    Step 2: Easiest way and normally people do is run Android an Android Studio with Apk Bundle decompiling 
￼
3.     I went across all the directories and found a unique file named encoded_chudio.wav
In command line as the decompiled version with jadx-gui gives a folder “chgame”
￼
4.     I kept traversing in all folders to get the actual file in chgame-Resources-assets-encoded_chaudio.wav
￼
5.     Since its encoded, it is linked with trespasser hacker society and clue is that our contest is on the weekend that they created a tool for RE I used
￼
6.     I created a solution.py for decoding the audio and the new image(screenshot containing the flags) are now in the new location
￼
 
￼
Hence the output to win this challenge they can have Flag   is
chctf{t53$p@$$35_h@ck!ng_$0c!3ty}}
 
