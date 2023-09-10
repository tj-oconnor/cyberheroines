# Elizabeth Feinler

## Prompt

[Elizabeth Jocelyn "Jake" Feinler](https://en.wikipedia.org/wiki/Elizabeth_J._Feinler) (born March 2, 1931) is an American information scientist. From 1972 until 1989 she was director of the Network Information Systems Center at the Stanford Research Institute (SRI International). Her group operated the Network Information Center (NIC) for the ARPANET as it evolved into the Defense Data Network (DDN) and the Internet. - [Wikipedia Entry](https://en.wikipedia.org/wiki/Elizabeth_J._Feinler)

Chal: We found this PCAP but we did not know what to name it. Return the flag to this [Internet Hall of Famer](https://www.youtube.com/watch?v=idb-7Z3qk_o)

## Solution

Convert the leading numbers of the domain names to ASCII and print out 

```
tshark -r NoName.pcap -Y "dns" -T fields -e dns.qry.name | awk -F. {'print $1'} | tr "\n" " " | awk '{for(i=1;i<=NF;i++) printf("%c", strtonum("0"$i))}'            

Running as user "root" and group "root". This could be dangerous.
chctf{cr3at0r_0f_d0main_n4m3_syst3m}#     
```