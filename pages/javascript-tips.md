---
title: javascript-tips
---

## ^^lodash let（^^不能出去哦，不过进来的，全盘接受，，，^^） var ---- let 不污染出去 hoist----提升 functions1->var2 先來的先，不過function還是老大。。。。^^调整顺序^^）^^**先宣告-再使用-let永远的神**^^
## 取餘--- % 例如 %2  0 1
## ^^箭头函数为什么会自动返回值=没有自己的this,用别人的this,伸手党啊】^^ ^^什么人在什么时候做什么事情^^
##
##
##
## js-proxy ![2021_02_08_图片.png](https://cdn.logseq.com/%2F7aa8ab99-753a-4230-847b-43a1c3a3ef4753dc6ec7-58a3-4418-a240-9fd77f3457052021_02_08_%E5%9B%BE%E7%89%87.png?Expires=4766353997&Signature=DcpWWoOIBXo-HmEqzxkpfrTZNLR~NbDS2c9ZNIdkC0cANfG0iiXQtrdeEYggsjOKlnWTfuphL2CCmnFGmAlYg2Kl0QHflldHQwlFmJmfbTkCtrjAUk8KdVveRIi80Zi3qGFKIk5CbEg9oHcpGGxdZvrXSGx3T1iAsYb-XjCA5Al~iANiXrsUp-QnKTsfhxSCkOkewjAOUx2fi9Q029Lsjr6lnuIor0Z5gh7Zl4j8xy9qwl3I-kPkQY0-T5id3SIT7mJxsR~3-cgPwVtikPXgVK97GwZ4VJMJUMtgIXgXjWCgcQNbuU2DWz2qWcrmQG7DYiGqGOdrwZ7Dpsy0Icm3Jg__&Key-Pair-Id=APKAJE5CCD6X7MP6PTEA){:height 508, :width 626}
##
##
##
##
##
##
## A programming language is said to have First-class functions when functions in that language are treated like any other variable. For example, in such a language, a function can be passed as an argument to other functions, can be returned by another function and can be assigned as a value to a variable.
##
##
## ![2021_02_05_图片.png](https://cdn.logseq.com/%2F7aa8ab99-753a-4230-847b-43a1c3a3ef47d8686ccd-51ac-4872-ab55-530f2924fee02021_02_05_%E5%9B%BE%E7%89%87.png?Expires=4766123569&Signature=AxE9BuocjxURj-1SOtzmKZvwM2odyNFduYkJ8UOWe0IX3ZdJJyzEKgoy~YDAoQ2i7Xgvrt3qWRr6UwxqKgff-CJZwNvptTiCGLKJ2K016J~wN4q7AtJQ4JgXsCBvRcz1qjsOn93kcLeZtJTWuaRJn-t3qjvVwegsT6wsOJXTdUYf6reoeaoz~z0VpVsWHiZNSKfcb5UOlncChqdcVu40DYRBgdzh7ytdBO1ar3SxYDHZFuLojPqW3HCYPcj7F73rZGs~Ny8ryL8ptnbcXIzTdPKuGTo6sNvmbQR5kRKDKQruI5Acqe1A9w4TTMxbV9YZR9UCgVd48~kcWJLYHPpzxA__&Key-Pair-Id=APKAJE5CCD6X7MP6PTEA){:height 321, :width 626}
## __proto__ chain-=-=-=--- 函數也是一種對象 函數--prototype
##
```javascript
 Object.getPrototypeOf()
```
## async.js -====
## 同步-我做完了，你再做
###
```javascript 
new Promise((resolve,reject)=>{resolve() }
.then()
async function test() { await fn1()}
 ```
## ![2021_02_03_图片.png](https://cdn.logseq.com/%2F7aa8ab99-753a-4230-847b-43a1c3a3ef47b14331d8-da6f-44f9-a263-4f13d340cc922021_02_03_%E5%9B%BE%E7%89%87.png?Expires=4765921537&Signature=a6q5cwXt53tpNWbpiWL51Cfjyo~q~ysWT5eVGvrBMew0DvzvZHyJXaBYF6QJuRsOjVcQeqcjKZ2jCvozjqQnuRMuOOvgJDZvcpOXWmJ6wuXAVfNuV8aO0FLXajDqyJL-ZJrQa0N-BbdjMmQ0Hhp87sbzFEp8E18wp84wdFfJfrLeN0oBQ16XociFdVLCx4BDeCHhR1f~mrSG9F~174HVs8nihXw4g8URWnjJ0uA76XHK3ZRBywhZL6hYvt7hbw4jtmX134OFAP~jvTcgK8ksHzQleobxkcYCvva4OwXp~UmJtJJDGZ4TRPBN~5RF48-G-lDsiLdzDVy~ROgYdmFUUQ__&Key-Pair-Id=APKAJE5CCD6X7MP6PTEA){:height 172, :width 180}
##
##
## 2020.2.3 ![2021_02_03_图片.png](https://cdn.logseq.com/%2F7aa8ab99-753a-4230-847b-43a1c3a3ef4733873a7c-a886-4b87-baa2-dd9d8eed07632021_02_03_%E5%9B%BE%E7%89%87.png?Expires=4765959000&Signature=nulF1GdfqSygC4LZqtjJactM7Zr-VA~t7IunWmODpCqzZ9tg4udPH4eQFpF8ZCV2wVWkV~PS7NTslSmwLNJ7-mWx6zQad5G-tR7NOXHETwRyrR5-CqSz-OkxZICkXwKxAjo1NMWSeUj9o3-eZWcbvQG2sB0zp9A2166T0lOuVvPMRWkDYV5iqi9n1NCK11c9NapusvaWUxSyslhVh~mbpKBCqYCvUcIKQcqU5JTpkE586S7ZeJy3zOfdvAnh0cpYW1gNzU1t9DmhGZeyiU3S2JKQTxblA7RCcRnF79iGwuyBIA76Ln--oANPOm7fnpp48lhaPZxQYNmXgcMWYSMqMA__&Key-Pair-Id=APKAJE5CCD6X7MP6PTEA)
##
##
##
## Did you know that you can assign object properties conditionally?

Instead of using if-statements and creating different objects, you can conditionally spread nested objects.

This prevents hasOwnProperty from listing an otherwise undefined property!
## ![2021_02_01_图片.png](https://cdn.logseq.com/%2F7aa8ab99-753a-4230-847b-43a1c3a3ef47089e5c09-a65f-4dca-b648-0ce83ac539c02021_02_01_%E5%9B%BE%E7%89%87.png?Expires=4765786889&Signature=H3jmi6TK30NAg9BE8Tv2grxMM-KFbTE7FwggBYwRt~sl8BAWF05Ag35Qcdzu4W4kL3CESP5XkqIytO6aYNbkjgrTQPP3OctIHlywaVN1wfzsipwbjijToTXyewj~O~SXahSWAcidbJs6dBy3IikwELHfelpe-PSclLgxufHn0T2uQs5Ii9B2sp3MT4k0y7aqOs2RtdxIrKM30X44gmjrtKSLPnsI8902F8NEp9IJ7Cgm7XVnDnY3PNCP-51qNrN~QICmjFpzFKuRQBgAbwYHnFu4QdIPNLTLJ84ult5ZytKXcPSF2f5fJahyvKoSOUR2tuhtFNaQ8H2i-Su6ujycYg__&Key-Pair-Id=APKAJE5CCD6X7MP6PTEA){:height 75, :width 112}
## ![2021_02_01_图片.png](https://cdn.logseq.com/%2F7aa8ab99-753a-4230-847b-43a1c3a3ef47f5690710-ea94-45b2-be17-cdaf3ec7bce52021_02_01_%E5%9B%BE%E7%89%87.png?Expires=4765787382&Signature=URSUOOdwgT-Zlr8UfX2Y1uJ9p62OtRcQCO2pWkRy2wOga-8MrkCL2NEBFHeTyaXgCXyq73hDD3Z-k4BSzVRslfBhtxwf0cRm5heTM3mKQoBlTnu5~-bC2Kg14Rz7GF7TkJDCA-ZS2u-8ljsM4Dx~uAV91AHz8aHDaxs7eDVEzsgs40JqUIRnvqYpjLJgXsdtZS6byANTirUxIgqPzqEcD~ll-FrndoJKiiGln9tDzqL8S3SC9UxZsUf1ddhsOjObF4Axia6Tq17~LCXLuSttk1AzsBqZZYnBlKnDfXa86TizxQ4EbASU-WPsVeuFS2Nvuxv0bNBB4cAlsW4IojnzjA__&Key-Pair-Id=APKAJE5CCD6X7MP6PTEA){:height 315, :width 155}
