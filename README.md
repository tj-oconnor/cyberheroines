# Cyber Heroines

Cyber Heroines CTF was an online Jeopardy-style Capture the Flag competition developed by our WiCyS chapter, in partnership with the L3 Harris Institute for Assured Information FITSEC Team From Florida Tech, Research Innovations Inc, and an ORAU Innovation Award.

# Challenges

| Name                   | Category | Difficulty     | Author   | Problem Description               |
|------------------------|----------|----------------|----------|-----------------------------------|
|  [Barbara Liskov](forensics/BarbaraLiskov/)         | Forensics | Easy           | [Josh](https://github.com/JoshuaHartz)       | Compiled Python Code (PYC)        |
|  [Magaret Hamilton](forensics/MagaretHamilton/)     | Forensics | Easy           | [Rusheel](https://github.com/Rusheelraj)     | Binwalkable Image                 |
|  [Elizabeth Feinler](forensics/ElizabethFeinler/)   | Forensics | Easy/Medium    | [Rusheel](https://github.com/Rusheelraj)     | Covert Channel PCAP               |
|  [Stephanie Wehner](forensics/StephanieWehner/)     | Forensics | Medium         | [Rusheel](https://github.com/Rusheelraj)     | Application Memory Dump           |
|  [Marian Croak](forensics/MarianCroak/)             | Forensics | Medium         | [Prajakta](https://github.com/MeherP2246)    |  Disk Img w/ Deleted VOIP Call    |
|  [Elizebeth Friedman](crypto/ElizebethFriedman/)    | Crypto    | Easy/Medium    | [Josh](https://github.com/JoshuaHartz)       | AES-CBC (Vulnerable Blocks)       |
|  [Sophie Wilson](crypto/SophieWilson/)              | Crypto    | Easy/Medium    | [Prajakta](https://github.com/MeherP2246)    | RSA (Small Primes)                |
|  [Shannon Kent](crypto/ShannonKent)                 | Crypto    | Medium         | [TJ](https://www.tjoconnor.org)              | Crypto puzzle (XOR/GZIP/XOR/ZIP)  |
|  [Lenore Blum](crypto/LenoreBlum/)                  | Crypto    | Medium         | [Robbie](https://github.com/Robster4911)     | Blum Blum Shrub in C              |
|  [Katherine Johnson](crypto/KatherineJohnson)       | Crypto    | Hard           | [RII](https://www.researchinnovations.com)   | Hill Climbing                     | 
|  [Dorothy Vaughan](re/DorothyVaughn)                | RE        | Easy           | [Kourtnee](https://github.com/kourtnee)      | Fortran Reverse                   |
|  [Anita Borg](re/AnitaBorg)                         | RE        | Easy/Medium    |  [TJ](https://www.tjoconnor.org)             | MovCC Compiled Bin (just ltrace)  |
|  [Maddie Stone](re/MaddieStone)                     | RE        | Medium         | [Sneha](https://www.snehasudhakaran.com)     | APK (Dynamic/Static Analysis)     |
|  [Mary Combs](re/MaryCombs)                         | RE        | Medium         | [TJ](https://www.tjoconnor.org)              | Constraint Solving with Angr      |
|  [Grace Hopper](web/GraceHopper/)                   | Web       | Easy           | [Sandesh](https://github.com/Sandesh028)     | Vulnerable PHP (Cmd Inject)       |
|  [Susan Landau](web/SusanLandau/)                   | Web       | Easy/Medium    | [Sneha](https://www.snehasudhakaran.com)     | CSRF Token Impersonation          |
|  [Radia Perlman](web/RadiaPerlman/)                 | Web       | Easy/Medium    | [Rusheel](https://github.com/Rusheelraj)     | NodeJS (DNS App)                  |
|  [Shafrira Goldwasser](web/ShafriraGoldwasser)      | Web       | Medium         | [TJ](https://www.tjoconnor.org)              | Flask App w/ CMD/SQL Injection    |
|  [Frances Allen](web/FrancesAllen)                  | Web       | Medium         | [TJ](https://www.tjoconnor.org)              | Flask App w/ SSTI                 |
|  [Sally Ride](pwn/SallyRide/)                       | Pwn       | Easy           | [TJ](https://www.tjoconnor.org)              | C Bin. (w/ Python Input() Vuln)   |
|  [Erna Hoover](pwn/ErnaHoover)                      | Pwn       | Easy/Medium    | [TJ](https://www.tjoconnor.org)              | Shellcode (Exec Stack/2-Stage)    |
|  [Carol Shaw](pwn/CarolShaw)                        | Pwn       | Medium         | [TJ](https://www.tjoconnor.org)              | Array Index Abuse (Tic-Tac-Toe)   |
|  [Kateryna Yushchenko](pwn/KaterynaYushchenko)      | Pwn       | Medium         | [TJ](https://www.tjoconnor.org)              | Linked List Abusing Pointers      |
|  [Ada Lovelace](pwn/AdaLovelace)                    | Pwn       | Hard           | [RII](https://www.researchinnovations.com)   | Tcache Safe Linking Exploit       |

# References

- Challenge prompts all begin with a [Wikipedia](https://www.wikipedia.org) enries and Youtube videos that are all individually cited. 
- [Josh](https://github.com/JoshuaHartz) used the code from earlier AvengerCon CTF by [TJ](https://www.tjoconnor.org) for [Elizebeth Friedman](crypto/ElizebethFriedman/)  
- [TJ](https://www.tjoconnor.org) used ChatGPT to create (and then modify) the code for the [Carol Shaw](pwn/CarolShaw), [Sally Ride](pwn/SallyRide), [Shafrira Goldwasser](web/ShafriraGoldwasser), [Frances Allen](web/FrancesAllen), [Sally Ride](pwn/SallyRide),  [Mary Combs](re/MaryCombs),  [Shannon Kent](crypto/ShannonKent) challenges.
- [TJ](https://www.tjoconnor.org) used ChatGPT to create the CSS/HTML for [Grace Hopper](web/GraceHopper/), [Susan Landau](web/SusanLandau/),  [Radia Perlman](web/RadiaPerlman/)
- [TJ](https://www.tjoconnor.org) used ChatGPT to build and then modify [Kateryna Yushchenko](pwn/KaterynaYushchenko), which was inspired by DEFCON 2023 Quals: Open House problem.
- [TJ](https://www.tjoconnor.org) was inspired to build an SSTI problem by [this blog post](https://kleiber.me/blog/2021/10/31/python-flask-jinja2-ssti-example/) and used their solution in the README.md
- [TJ](https://www.tjoconnor.org) builds his binary-hosting docker containers from the template published by the Order of the Overflow for their DEFCON 2019 Speed Run Challenges.
- [Sneha](https://www.snehasudhakaran.com) used ChatGPT to create and modify the code for [Susan Landau](web/SusanLandau/) and [Maddie Stone](re/MaddieStone) .
- [Sandesh](https://github.com/Sandesh028) used ChatGPT to create (and then modify) the code, also inspired by our internal Big Brother CTF Web challenge for [Grace Hopper](web/GraceHopper/) 
- [Rusheel](https://github.com/Rusheelraj) and [Sneha](https://www.snehasudhakaran.com) created and modified code for [Stephanie Wehner](forensics/StephanieWehner/)  
- [Rusheel](https://github.com/Rusheelraj) created and modified coding using ChatGPT for [Elizebeth Friedman](crypto/ElizebethFriedman/) 
- [Rusheel](https://github.com/Rusheelraj) created and modified code using ChatGPT for [Magaret Hamilton](forensics/MagaretHamilton/)
- RabbitShield Infosec Private Limited created ideas with [Sneha](https://www.snehasudhakaran.com) and shared code for  [Radia Perlman](web/RadiaPerlman/)
- [Kourtnee](https://github.com/kourtnee) Fernalld used Chatgpt to create and modify [Dorothy Vaughan](re/DorothyVaughn)
- [Robbie](https://github.com/Robster4911) used ChatGpt to edit a few parts of [Lenore Blum](crypto/LenoreBlum/)
- [Prajakta](https://github.com/MeherP2246) used FreePBX server, MicroSIP, and PhonerLite to simulate [Marian Croak](forensics/MarianCroak/) 
- [Prajakta](https://github.com/MeherP2246) used ChatGPT and inspired by [CTF101](https://ctf101.org/cryptography/what-is-rsa/) for [Sophie Wilson](crypto/SophieWilson/) 
