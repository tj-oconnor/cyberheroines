# Maddie Stone

## Prompt

[Maddie Stone](https://www.wired.com/story/maddie-stone-project-zero-reverse-engineering/) is a prominent researcher on Google’s Project Zero bug-hunting team, which finds critical software flaws and vulnerabilities—mostly in other companies’ products. But her journey through the ranks of the security research community hasn’t always been easy, and has galvanized her to speak openly, often on Twitter, about the need to make the tech and engineering industries more inclusive. - [Wired Story](https://www.wired.com/story/maddie-stone-project-zero-reverse-engineering/)


Chal: Our [Cyber Heroines CTF Director](https://www.fit.edu/faculty-profiles/s/sudhakaran-sneha/) created an APK in homage to her favorite [Reverse Engineer](https://www.youtube.com/watch?v=U6qTcpCfuFc) for hiding flags. Reverse the application and return the flag .


## Solution

Android RE 

- Decompile an Android JADX, Apktool, Bytecode Viewer or Android Studio.
- Easiest way and normally people do is run Android an Android Studio with Apk Bundle decompiling 
- I went across all the directories and found a unique file named encoded_chudio.wav In command line as the decompiled version with jadx-gui gives a folder “chgame”
- I kept traversing in all folders to get the actual file in chgame-Resources-assets-encoded_chaudio.wav
- Since its encoded, it is linked with trespasser hacker society and clue is that our contest is on the weekend that they created a tool for RE I used
- I created a solution.py for decoding the audio and the new image(screenshot containing the flags) are now in the new location

[Full walkthru](solve/Android_re_walkthrough.docx)￼

Hence the output to win this challenge they can have Flag is
chctf{t53$p@$$35_h@ck!ng_$0c!3ty}}

