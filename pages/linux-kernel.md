---
title: linux-kernel
--- 
tcp
## **“许多操作系统教材都是重理论而轻实践”，“多数书籍和课程为调度算法耗费大量的时间和篇幅而完全忽略 I/O，其实，前者通常不足一页代码，而后者往往要占到整个系统三分之一的代码总量。”**
## ![image.png](../assets/pages_linux-kernel_1616139492873_0.png) ![image.png](../assets/pages_linux-kernel_1616139606073_0.png) ![image.png](../assets/pages_linux-kernel_1616149399860_0.png) ![image.png](../assets/pages_linux-kernel_1616149464486_0.png) ![image.png](../assets/pages_linux-kernel_1616149511156_0.png) ![image.png](../assets/pages_linux-kernel_1616149636388_0.png) ![image.png](../assets/pages_linux-kernel_1616149746993_0.png) ![image.png](../assets/pages_linux-kernel_1616149849604_0.png) ![image.png](../assets/pages_linux-kernel_1616149959515_0.png) ![image.png](../assets/pages_linux-kernel_1616150011261_0.png) ![image.png](../assets/pages_linux-kernel_1616150052265_0.png) ![image.png](../assets/pages_linux-kernel_1616150142151_0.png) ![image.png](../assets/pages_linux-kernel_1616150186506_0.png) ![image.png](../assets/pages_linux-kernel_1616150225058_0.png) ![image.png](../assets/pages_linux-kernel_1616150488024_0.png) ![image.png](../assets/pages_linux-kernel_1616150543308_0.png) ![image.png](../assets/pages_linux-kernel_1616150589269_0.png) ![image.png](../assets/pages_linux-kernel_1616150638081_0.png) ![image.png](../assets/pages_linux-kernel_1616150774726_0.png) ![image.png](../assets/pages_linux-kernel_1616150938029_0.png) ![image.png](../assets/pages_linux-kernel_1616150970633_0.png) ![image.png](../assets/pages_linux-kernel_1616150997510_0.png)
## ![image.png](../assets/pages_linux-kernel_1616139188766_0.png)
## ^^Linux-0.12 版整个内核源代码只有 463K 字节左右，其中包括的内容基本上都是 Linux 的精髓。^^ ==拿 Linux 0.12 版进行学习也有不足之处。比如该内核版本中尚不包括有关专门的进程等待队列、
TCP/IP 网络等方面的一些当前非常重要的代码，对内存的分配和使用与现今的内核也有所区别。
## 简单说明程序的主要用途和目的、输入输出参数以及与其他程
序的关系，然后列出程序的完整代码并在其中对代码进行详细注释，注释时对原程序代码或文字不作任
何方面的改动或删除，因为 C 语言是一种英语类语言，程序中原有的少量英文注释对常数符号、变量名
等也提供了不少有用的信息。，最好是循序渐进地从 1.0 版本开始直到最新的正在开发中的奇数编号的版本。
## ![image.png](/assets/pages_linux-kernel_1614230389108_0.png)
## ![image.png](/assets/pages_linux-kernel_1614232006098_0.png) ![image.png](/assets/pages_linux-kernel_1614232441839_0.png) ![image.png](/assets/pages_linux-kernel_1614232515645_0.png) ![image.png](/assets/pages_linux-kernel_1614232608021_0.png) ![image.png](/assets/pages_linux-kernel_1614232721020_0.png)
## **CPU 通过地址线、数据线和控制信号线组成的本地总线（或称为内部总线）与系统其他部分进行数据通信。地址线用于提供内存或I/O设备的地址，即指明需要读/写数据的具体位置。数据线用于在 CPU 和内存或 I/O 设备之间提供数据传输的通道，而控制线则负责指挥执行的具体读/写操作。对于使用 80386 CPU 的 PC 机，其内部地址线和数据线都分别有 32 根，即都是 32 位的。因此地址寻址空间范围有 232 字节，从 0 到 4GB**
##
## ^^/proc/ioports ^^ ![image.png](/assets/pages_linux-kernel_1614229849878_0.png) ![image.png](/assets/pages_linux-kernel_1614229883711_0.png)
## ![image.png](/assets/pages_linux-kernel_1614229747412_0.png){:height 485, :width 626} ![image.png](/assets/pages_linux-kernel_1614229617498_0.png){:height 24, :width 251} ![image.png](/assets/pages_linux-kernel_1614229641109_0.png){:height 29, :width 257}
## **通常一个 I/O 控制器包含访问数据的数据端口、输出命令的命令端口访问控制器执行状态的状态端口。端口地址的设置方法一般有两种：统一编址和独立编址。**
## ![2021_02_20_image.png](https://cdn.logseq.com/%2F7aa8ab99-753a-4230-847b-43a1c3a3ef4729ba0663-a242-444d-bc0e-cac4b7768dd72021_02_20_image.png?Expires=4767434411&Signature=DYd~-Q8aul06YV6hRml0dq17KV2IGGxwjt6MdFXS3ETy9jVXOAc8A0Zx33pQ4Y6oBMo3PZOD-A-q5QXuvOeq-3GXNrBsAa4s-zniMuBgxu93DMoPZZOBfEMnnsFvDNSip8FK-eCrDffz9CfFoAa1PlrgjwSjGCElOboSwRYrHNfcgVz3zUV3erEUU2QpdZXgDPS4jGVLhMTUVq~R6hMbc~3dUOMxzrfxOdMwVzoyRoWuYB8sJFOnozgUqjq6duhRma1lPa6Z92Euyzv03cBVxNX-DQNZn3QPx84Rc~XqpD8L804rRkKCsgaxo3MLmDEfJHOvM-ljhdKkzy~4mw5TLA__&Key-Pair-Id=APKAJE5CCD6X7MP6PTEA){:height 105, :width 206}
## ![2021_02_20_image.png](https://cdn.logseq.com/%2F7aa8ab99-753a-4230-847b-43a1c3a3ef4792502267-d22b-44e6-b726-da452c0d90262021_02_20_image.png?Expires=4767434681&Signature=WqMKFvfTnuRv0mQ-ABw2FctE2vtHB9HXV~wtDUyRpmVud5ZLsKcF5E0PTigkB13AlcMhIXL5Xi5TQnw7~Ga1Y2UNFlP8~hlNLPFuwb1h4vus-ddwuqMcaDNFEucnxz1S2OEhM-NWQ~0rbxcwSxiSH22bzR5OksGmlUqfZRyyHIPfi5jnvhbsIgVZtgoukzT4vdw5lCxnPLBUDQ2N-ybT8OKYl1raRuD1JjdUfBZGvQcMsiwggcunyHVAsFyqGhcqnT9vjMxDSyAKI8WtQZqzLEq3eYdvCkJIAxwK4pfA272GPI0WdT~pj5FY85zlMsgW0VS9gakzcziuM5tYmwNqNg__&Key-Pair-Id=APKAJE5CCD6X7MP6PTEA){:height 122, :width 260}
## ![2021_02_20_image.png](https://cdn.logseq.com/%2F7aa8ab99-753a-4230-847b-43a1c3a3ef47971cc4d6-97d9-4b3e-bf88-bea1ff36ceea2021_02_20_image.png?Expires=4767435390&Signature=jwSUleyk4sS4rq6eAO5RmpTbxx5oGKirjHPMfO9PDVzLtL3pDN4OJValVLUSFWKc2epGQwtyky54WeG~ZDgNAEVrnhd713zP2nXXXQxepbo-thbFsuPVRoHUZ5g7f7ITno4-KyNgGhQUPDx5ZG31k85md-SK3EN193UOwyygeQkPwUifcYBR4NMK7klqofRKJzmcZTIaxlXOyVJiOXtRE5oFNBPkAfkNU6FNpI5nD19Ck-mp9aTvZTAHOHqhrVPBnedFbs9dfaK9ZZgjKB8kZc1eb~eYXqDO6N~oWNe4RoX~PkVyqRWOwjQkmMfrgcnrcIWJb1WHF1KPV4d1I4YsHg__&Key-Pair-Id=APKAJE5CCD6X7MP6PTEA){:height 117, :width 63}
## ![2021_02_20_image.png](https://cdn.logseq.com/%2F7aa8ab99-753a-4230-847b-43a1c3a3ef4777d390ca-7f5e-48f5-bafb-ec5042cef9fd2021_02_20_image.png?Expires=4767435720&Signature=fhV3x~~OnZ~zvWxxiQRXL1ocrf~WJLzpS8oxethftV1nyvOmQN-qnwGlB~hgQsg~3twVKHP72r6frs~HToWET0qej94r-kWwkN1dXclnx03NUmXrO6M6v-847rLKoViYnhbngL9-y3zx493wIvtfEqvWBvgN-FALeUwvU2H-ZZY9PZqynwWKHJv3yt2OA9MDyJmSnCRE-hIFGIo9FLWFjFqUH3WoGkKG1Va5J8HDGR8n~Flzwiz-bumLE~Fr4GTDKnYHc15TIMrbj10gTO~bdfrNvN5LUH4h0vkReV0M12eVNIkzeOXaLwOWvEAylBUPNLwVE2Hihpw2eczwQ5JKzg__&Key-Pair-Id=APKAJE5CCD6X7MP6PTEA){:height 73, :width 168}
##
## ![2021_02_21_image.png](https://cdn.logseq.com/%2F7aa8ab99-753a-4230-847b-43a1c3a3ef47f8262a5a-2715-4559-93fb-5201b4fd69362021_02_21_image.png?Expires=4767439635&Signature=Ey9hGnBuNmoq1sOKKf~PNwXyeoGNlvBKsO4olD8g9y-8cusv2qAbZimMg0rsM~PL0Cl0RQFaLk7W9u67YBctHerHuYutIANkcP2CKSZMgMihTi1aR-9BY9AB1q7sxmCQCcBAm-xcgpinlF15FgAyxY4RMWssU9z7bR4o1aHWbeXoA4rHBpjwjOUiIHleZsU6U5lHGZR5P8cdanDHBEfcleeaVYZoyPOGJykt8Pvh~i4fEgjn81jjvIHqQFrYShb25ct8KLobaGPngnZytUP8d8rueWxCHqy~uHmgVH5Hqg5IJjPHBWMGFMf7zEE0KoPgcTGlTuIRC~gpqTI2-pwtOw__&Key-Pair-Id=APKAJE5CCD6X7MP6PTEA)
## ![2021_02_22_图片.png](https://cdn.logseq.com/%2F7aa8ab99-753a-4230-847b-43a1c3a3ef47d2de43d4-0473-4ba7-98ec-849b04bd776e2021_02_22_%E5%9B%BE%E7%89%87.png?Expires=4767576773&Signature=f78R9bAiXhHYy6U5VHsGcOum6C0G2qqgm6MZPwfJr~fNSuFT4DhEoYra20vUX74YR4Teoh98yazarCcwCh96cdQDfkGEpfj5m1ao7~2ffiT8~NUEy03BGsVif3JZgl2hX3PwNzWlcwJqrk7w~zhXFCXLW6qVnTEd7sptSNiDlq-J-Ci4Uux8BlaQXyVnu98Gax11DrJ9oUXw6YEWf6lFs4c-FLebOS09h2S~UJamGpKKEMLTFgNNt6TU4O4NCqpGCXDEcYg~sbAvKVsSqdMkNEKmb8le7rfdLIFdEFPWqyeQ-NLFUcoJ-Jz~VV9NN8sFwJOXGw0DZOR0WcgHi6pdzQ__&Key-Pair-Id=APKAJE5CCD6X7MP6PTEA)
##
## 通过设备号获取
## ^^高速缓冲区 非常有限的资源， 内存自己控制，检测容量^^
^^映射关系（内存与磁盘之间的映射关系） 应用程序和高速缓存区的交互api 磁盘与高速缓冲区的交互api 高速缓存区的管理系统（循坏列表+哈希表+单链表）^^
## 用户与磁盘进行文件交互时的流程
## 磁盘与高速缓冲区的关系
## 加深块设备驱动的理解
## hash 循环链表 单链表的使用方法
## 高速缓存区的工作流程--> 高速缓存区中存储着对应块设备驱动的数据，当从块设备中读取数据的时候，os首先从高速缓存区中进行检索，如果没有从块设备中读出数据，如果有并且是最新的，直接和该高速缓存区进行数据交互。
## ^^buffer.c^^ 高速缓冲区--低区和高区 一一对应，高速缓冲区的头--结构体 状态时间信息
:PROPERTIES:
:background_color: #793e3e
:END:
## 空闲
## 获取该资源对应的设备和块号的高速缓冲区
## 从 buffer_head 的b_data数据区域拷贝到要用到数据的内存中，（hd_read(char * source char* desbuf uint size)  source ---> bh->b_data desbuf-->）
## ![2021_02_22_图片.png](https://cdn.logseq.com/%2F7aa8ab99-753a-4230-847b-43a1c3a3ef47f2809db3-5bb8-4bbc-a0bb-9eb8cfc3169e2021_02_22_%E5%9B%BE%E7%89%87.png?Expires=4767591609&Signature=SwpUsVv2FFEFGpN0aRjBon9oOIEwPxg8B~n~gL7Gw~YJ5a2dPjsWGudx3VIXagF0dqDEL08b0OrfFdf~i7vP19T7-0vQpe5z5lBWo2~0Cyxyp4BDfIl3Kr7k8OomsBuZ~FFnAJFUoX7ignvdB4aWdxpmUa6rqtpsKa2bd0QjR7pWWL5hU233G0YVGpVeupwfhXoxV40akJmPyeLSRhc-pZOsXYdoG5EcLVGVschBZkJFw0R0CUN0LpaY9bl2dPmzNehS4sRz~UAIf0l5Q644IjejLrWTXL1BmZWQ97ZVRap6KWgaCo6DAACSalRgqy4D2YTcyAScVX2S9ffOw1wsSQ__&Key-Pair-Id=APKAJE5CCD6X7MP6PTEA){:height 31, :width 597}
## ![2021_02_22_图片.png](https://cdn.logseq.com/%2F7aa8ab99-753a-4230-847b-43a1c3a3ef47d49322c6-d2df-4a1d-bc2d-e490a21d8ae32021_02_22_%E5%9B%BE%E7%89%87.png?Expires=4767591313&Signature=PrOAxS67cYA4hiPBFpS9NjJeiNny9CY2ApSVYR5SyB2mz1yRj74h1okqz-YqnnGdgchJw9EiQgTy3dDMuWPpK-YjqsYpIHp~tI1C5heN0ZbeATbxVbn81PYdiRQ-HSQNlLw2pNqaeVtflQ8WKBeOyDZxB5jjVZrjnZCwGn3mNPAYp-TEQo4nvgYAonZy1tXA24JUDJseRzTD8BpDPk9FszlIQp1~36uU2lZrNH2SvnnMOp-8WrAp0cAXLeqa-Reo19DRqB8pCavzm2kw8yetzVZvetjozQw3YyDaArxSxKHtBnk~Thiofgof551k154a0-Fkhte0eVRs~QpAfycsHA__&Key-Pair-Id=APKAJE5CCD6X7MP6PTEA){:height 32, :width 594}
##
## ![2021_02_22_图片.png](https://cdn.logseq.com/%2F7aa8ab99-753a-4230-847b-43a1c3a3ef47c2b55f4c-b03a-45d5-877c-efeeee37dddd2021_02_22_%E5%9B%BE%E7%89%87.png?Expires=4767591251&Signature=RgknkGWbYRU49FAimnXj-blQA~Gyc0QCbddR~Dhbe3cDmJJ7R-uua1NglEXMAlSaiSniet-pfKLtfWkN23tJby2IO9wWQukAhp59fFxeY90p52GXa4ty7tKVg0ABX8VmGB-l8R7UttwvlNB5lViNwnUV2Mf2p3grcAoR22Orjd5ThoA8xvOUVgoo9x46iPATrfOzok7cw6AyOfqHPnfnamOC5whdNkS9mxpRp5IqCoD-pe4E-dYUMMli7UtQNydfpBbU1Ad-nqgwBm2T8~SkAaYpBGnrmmfd91nTHuxEGbICC6U5CDf-UYHSw5-iYgdM2bKHKWjujkN27v24uC65iw__&Key-Pair-Id=APKAJE5CCD6X7MP6PTEA){:height 38, :width 613}
##
## ![2021_02_22_图片.png](https://cdn.logseq.com/%2F7aa8ab99-753a-4230-847b-43a1c3a3ef4746542ef5-c08d-4bfd-907b-163d72e038452021_02_22_%E5%9B%BE%E7%89%87.png?Expires=4767591009&Signature=SVuN6Ktcz3Uohb6K~0g2y7w7eMK~GbNPh90GaLWRaMOiihr8hi4QO5VMdyOuBBvGv7diL37KjjJS45dsIC~js14Bx4uT2f8hrcP-7NYA4Kjtqc879WL3ayCudIGl2FgsSNPjTGzk6s-NVc2c96u4YF1eFtSg0Omr2R6oqbASGZxnPAWyZkNLyVs2QiK3d976gsxdjfSiXP7Ka-X9msVdCeHiiTz9rg6IpdOv4Yh44J-MD0Jd-FwypRyA8JM-qAT1ETzhUQzwo5o-V5aiVeniVjJfFgU~~qMyh1-ejhg~6Do3ul13OhZmh505WXo3KLt5U9QAp~uA2iglMUdGlW5~3Q__&Key-Pair-Id=APKAJE5CCD6X7MP6PTEA){:height 32, :width 609}
##
## ![2021_02_22_图片.png](https://cdn.logseq.com/%2F7aa8ab99-753a-4230-847b-43a1c3a3ef474f66eedc-6747-4309-b785-77ab2a9f7cfd2021_02_22_%E5%9B%BE%E7%89%87.png?Expires=4767585547&Signature=Gd2YNwJFBkaDT4wYGJ7-SyEs3M9~qt6W07JpD7NKDmuudJj696F0HYw~RRBEIBgzxZq9~KXAXEimNNHaZPIF2IKK2HZ06GXdoxUDh3-C3SqFAhd1txCQo9CiqsDq3mem6cVODBrE9PUJU5MGGl2pVuG9abkeLmTvOd4ksflxcO7eoEioxtBYXv6lsTpWqN~jSfUBSOK0PNFu21Pv6s79q1R1uKA4IGK5gsUwp6HWSK8AOD9su8ItrX28E04z7pyINm8Z4BTU2yVS8qygUYrvGvjLqFJ3hes7xmHt0KZOtXtRsrgGe4eb3D5ehrsoltAec6lZk~3iH2vb1f7iSnbdDg__&Key-Pair-Id=APKAJE5CCD6X7MP6PTEA){:height 24, :width 616}
##
## ![2021_02_22_图片.png](https://cdn.logseq.com/%2F7aa8ab99-753a-4230-847b-43a1c3a3ef478a031f3f-c104-4be8-a08d-a1e17c5fff0c2021_02_22_%E5%9B%BE%E7%89%87.png?Expires=4767581676&Signature=G61258vdncTWk902bdP-u39fBJklesUPNz-251Kussxj-9tHEMxSq2Pt89mLM4DFU5aVRPoOzxGgT7n2mf6GA7onk0X8LN3dp7rSjpLM5G272ttQOZbBDp5aLBhtvRKSkssgVnygrHpX8w1LFZqJoizIiEz~T575Ew6RCvPfWqrfjBsr6hAjclD7aLfR2RSbn8eW9CWqWmosIIIo7B6RhmTRaPIGUbFN52d10kKABKdqm6mYewkgzGNNeKewEBIMgGv-Ox3YReP1RhJah25~1-pZ7aLXtfdPT~k2HLH4sBUEFMUNlhi1ww52aDgPwTpKMgtdJl5s3QIpbrgHl35Vdg__&Key-Pair-Id=APKAJE5CCD6X7MP6PTEA){:height 20, :width 624}
##
## ![2021_02_22_图片.png](https://cdn.logseq.com/%2F7aa8ab99-753a-4230-847b-43a1c3a3ef47f37da039-607f-42fb-8ad0-33d312b4a4452021_02_22_%E5%9B%BE%E7%89%87.png?Expires=4767581461&Signature=Y5oPJWWEkGql2E-ENgKLMoPNY0xlA1TfINCQF45tMlVr4P8sh33eIKoJKjS3uNJMvL7wpUpt1~l-9HsJdxeDP7ZayFuse8POPzK9XZPI8ho2gXKPLYNj2Pz3L9T14nJRAZ4lJz93AIUCJA99wriXZk7jnR8Rqwb9uNH3r4Uc4DjFFXq-4CX0dPzZvh-enA0f1FHBmSmR0-VRNYGeoGSwgE~SxK1MWHre~Duetz6tW~Sf003zHq9WnPFdBMCYGWg2g~Jx9aTZ9OvCVeyjVk~oundkXbHtRgGvRxHecJOqnUWCVfdxwdgTVwnhFADLpvcyUvW7MmKuI2Z7Lk4G18eOYA__&Key-Pair-Id=APKAJE5CCD6X7MP6PTEA){:height 23, :width 619}
##
## ![2021_02_22_图片.png](https://cdn.logseq.com/%2F7aa8ab99-753a-4230-847b-43a1c3a3ef47d9efcfd1-65ab-4fd4-97c0-4c0d562c37d12021_02_22_%E5%9B%BE%E7%89%87.png?Expires=4767580342&Signature=dFDmoVaSRABTr~DdJsyEPpBwPIAE9rZ4yt9fVj44YxQEsRUib3uoz6WhjgIaU~xDKh24-7s0MqlJ0p4ixfUbNyn9v5SkSQVMTyCaqJo5XjEQHF0MaZyLNSc3SA~vBrA4doFP0AwulpEiPkmOeUQWcpAbLE5A5O0SNQUnRPUKmpwKgxTgpX5SiAHmmGwZ93Np6r170PCnTZisqowQDBkkSe3NPln45nb0up-FqMsaWrN-AaMSpm3Kjc2ckoTrEIv1ojvqE5EYhqqEJqCT82zqqID7OQkwF-J7KXMGyBR5k~pSFuagIs5idvc6Ru1ErFtWGEj~7VhSqxU6UsmNhImVag__&Key-Pair-Id=APKAJE5CCD6X7MP6PTEA){:height 26, :width 616}
## ![2021_02_22_图片.png](https://cdn.logseq.com/%2F7aa8ab99-753a-4230-847b-43a1c3a3ef473b812396-c0e0-4674-b93f-bbae2e82f2ae2021_02_22_%E5%9B%BE%E7%89%87.png?Expires=4767576846&Signature=Q3vdCvJjjD4RdF1oKSfaojQwEWyOfo0XviEkrRsFL9YLWi~shXh2BhJJkTjrTMYQzTuTwzOdcoAbr4qZPqZXDDg-YuNUXsUxWCLAPTF-iohCwv16pnUnqD389vMou9N~LpPCGuUrZghdaUGUMfGKHV2V-ohKs2Vi2rHgebKYb~RYowue1zu7nVpV0E4laQBezHn7DezS4aqk9H7yucNPXWL23Re4KvKdYZem6EIT6Vq0-QvWfO9FSD~Vvb4-7iYZ4HUxDDPoNKbKDU9~xUhFVSPu97d-1gX50E21qju-55NBR8MHRUcpA5wG0oECLReIqxIACqBw1q32TWswfEngLg__&Key-Pair-Id=APKAJE5CCD6X7MP6PTEA){:height 50, :width 636}
##
## ![2021_02_22_图片.png](https://cdn.logseq.com/%2F7aa8ab99-753a-4230-847b-43a1c3a3ef476f0ed879-3f66-435a-aced-db234d4fd19e2021_02_22_%E5%9B%BE%E7%89%87.png?Expires=4767576367&Signature=VN37kdjZkLbuZfVUC5vdzzoYID7JteQWCzcjbVkhpqQchgT~0~VttfC8fukMtBnpGcr24QH5RBkV1GoFhiP-wygFoAd~Be2VxD3p0PFQHZ8NYvB11HkwxtuwLJ8ftvlRC8Fikhaxhy~A9wWkaT9sbIwf3V2vz14Bl7IY8-VFpNZEwVJYhzjdSjgW2nON5Ap42ZbERAK1biTCCVg2Y-f5qfDIVCpaEJkxD0WJVNnZyRFyY7WgrJ6N-zpqie2LbWSDj9d2sRNozvRyI3eYH3G1hr3Kolf~SoUL1oEjKEYOXp1qNrzusUpFam3FREYT3DeoddSrB-2WrytYF~ManYukVg__&Key-Pair-Id=APKAJE5CCD6X7MP6PTEA){:height 44, :width 631}
## ![2021_02_21_image.png](https://cdn.logseq.com/%2F7aa8ab99-753a-4230-847b-43a1c3a3ef4737fc24ea-abdf-4de8-bdd4-71fe6e7d9ed62021_02_21_image.png?Expires=4767438788&Signature=DPbo~sFyp8LeGra-VkgQU~NdYzyig0tH8if8hI1LqeNryPk5ITFXRZjERLeF8UFF2VSuTuoSA8emoxEomdv-OLAdD5x19pHtQPWLlnf~U5Zd0FKnfnOuHG509MJrpJP0ux8GFbnTSqqIhl02f3u7WxL8-9Or7c~6~hgBdu-~-3Y-MkwEr6mUyEQ8LcQkZbT6ytu~aJX0mwD70E5aZK0nfUuL6doL7E2kYaigljCLoUx6m-KAdhWLbr4OSh21lv2H27oqzDQSH75rOvO6X0m7Iwl2N6IuhA4Mpf52D3G57HZ~I6PaLe~Z-LoNya98Xcy-b3dtsOosilt33HeT0HTMiw__&Key-Pair-Id=APKAJE5CCD6X7MP6PTEA){:height 59, :width 616}
##
##
## ![2021_02_21_image.png](https://cdn.logseq.com/%2F7aa8ab99-753a-4230-847b-43a1c3a3ef470148afd0-a98d-4e9c-a14e-d4a3fa38b8942021_02_21_image.png?Expires=4767440207&Signature=P6oz-uLg72Ww0zf~3EyTw0lDIzwD8qpakQttLlJcc-ngMb0bCqRV95UqtUQnzE31b02lq~psmLyXnQ3s5XiI~bHuiEQcSrwy147cSJzzL-ud9gF6b--B2hpPaP7FEo7InwYsGN5a1xju1JS~Ul3T3cKbRTULyDQlPJkzXwL3PjOHhbNVFqBDXyAKgJWLcqxWpXRvutSiuR9IONZT1OWtyIrYchDf2eoO0TlLcDOxyz~trAZS2axR6lWcQ7oaCsZYdtwGayrqztJjDjFyVt3xSjAHNoi9VO8NjhKFqc-7Izq3w45iuWf~Dq6emY-8OS~-fwe8yJanHqvxGsxvye~Zbg__&Key-Pair-Id=APKAJE5CCD6X7MP6PTEA){:height 30, :width 616}
##
##
##
## ![2021_02_21_image.png](https://cdn.logseq.com/%2F7aa8ab99-753a-4230-847b-43a1c3a3ef4750389b19-a1b6-466b-a33a-0d28ee69c2782021_02_21_image.png?Expires=4767438115&Signature=SgtVwBCP3pgmuMtxECcj2Y0G79j4Z~7nmVGp0g9B01~k3O15dXdKkKHcHKEK3TjFaoEVk9U2-okv5j0EGAue6tJMl1qRec3P~ZsBIDpzk1Pl5ZCxnRHpGvsKAIS0b6DI~jhCPpSa7ulCpX6Ww1a4YyJJqbG6CswonJZ-gAVRaiuRsMUlOzqpR7UztE5bVXRcK1Nlk9BHQma1~Ri5QPux3eVJraQXqyCw5SbNCAFY8j-1C2giSO-Adjb3ZTye~WvPK5mkGelF0pDF6w526oxqA41icxXghmjWWrxI6g2Md-TLn9VDFcDsPhuAKTvS1se0iScZHxAP6Alcko1OVaTwMA__&Key-Pair-Id=APKAJE5CCD6X7MP6PTEA){:height 50, :width 616}
##
##
## ![2021_02_21_image.png](https://cdn.logseq.com/%2F7aa8ab99-753a-4230-847b-43a1c3a3ef47ebe44c4e-42aa-49e6-b2e3-fd84179d25a72021_02_21_image.png?Expires=4767440951&Signature=Yq~-kwG0~8e4BJvrymsCP1h~l780as7AQzNkKsYi7DRxsZnjXFi6f5uWq-dB-v-QUp0fCZ7BmG~RS5fvJ0-vHOL8I7gbtLxw~0nlTQ9trsKoLtx~8Ai8RXVSVmvXR2bC4BZcNIeWcUy0D9GT1XhPBGcshYax3C5CXcRHPsm-eImqFHWGiK9qzlqBff~Jx-V7q7e0IfEkee1syFuBwDnKfjcEJMNO8sI8HW4xyR6ITmOPYQkqFtipAqCpbn7WGAQRMpJGs8SMwquXQ39azVYUUf~3VdMbyYpEnS7W0dpjUqbZ9HNemzKIntLbs5lnBfmyMoVt1qf7DCdENw0TuPJ2ZQ__&Key-Pair-Id=APKAJE5CCD6X7MP6PTEA){:height 73, :width 595}
## ![2021_02_21_image.png](https://cdn.logseq.com/%2F7aa8ab99-753a-4230-847b-43a1c3a3ef47dcf543db-df82-4092-b9b7-b8d42df3e9a32021_02_21_image.png?Expires=4767475944&Signature=gc9SOCH7pR0a2TGieFRLBSaqrGmFZ6fWm0k5YLIiCRGpbKXTMIT6IY05iiIjjpSD~XmFfIUFDl~Sz~ZUy5S0YSOnV4ShPnxWoKqvJBF58a1azqknQOb6~u8R3b7i5oIcSpNV25YLWs9UYGmH5sQS~sMnbJAH2Kh-P0nJaJ4p7rAyjyqiEjgcEdydZz~dRiIX2JTnYM7iMkcLWw9SMs9dtgDlosMITNw~A6FKQkvOpdT7wrRQSRkeyfL02Z7eX6VD2bDkwyA7Enceq~ypnTqsWh0hBL2io8Pwv5PVoOBDpTltsk~a-2haOETXOt0jWA0ootCUMvv39SSrsp4JjBJsqQ__&Key-Pair-Id=APKAJE5CCD6X7MP6PTEA){:height 34, :width 607}
## ![2021_02_21_image.png](https://cdn.logseq.com/%2F7aa8ab99-753a-4230-847b-43a1c3a3ef4796501f36-06ad-4dae-ad50-e094bc6a5df12021_02_21_image.png?Expires=4767473089&Signature=MgrQBKr1TitC4a5XNr9IZ~0lywqhAY-BIxhrHrAODs1BARJYQfFf1exWVCzbriJdbsYoBDAQh0ybYTRO0AwyK6YkQ4SC2yrvuX3DBY5iDEt8OAEbZULoz0QQGX-QHk2iv2bK0R7boNjowG2hvK5U5eVcPE0VPiwaSGKKwoKteRIHEqDb59Wntclk5PqyYmc6mOy~w~wj3mfAMNTlMKNDGxbdP9BZKfqdhJ5sy5BSUWV~7RWcg1viUCSQ0bEXV5M9h3pyieYSrjx~sEBVzGg06tNL8yy1uLW68oQhSSYVyIoLn0-7bNsvtHxjndLXj9vRDfbPXsZmrY~GIS2rEp8EFw__&Key-Pair-Id=APKAJE5CCD6X7MP6PTEA){:height 43, :width 595}
##
##
## ![2021_02_21_image.png](https://cdn.logseq.com/%2F7aa8ab99-753a-4230-847b-43a1c3a3ef4742e18b12-2636-4e15-9631-39c9e0cd6ab62021_02_21_image.png?Expires=4767473134&Signature=dIUJfWXYn9R3OnezqZMtlOhuwemJtLWBZNG07Qm45RJT6k0-YvwElesF8ZLOnQ95Od1vTKCczsr8DX7kkpNxSnXEjexKWeKWI3dV6xNO~RdSXe2IJ24BR527QO3TkmwSm1d03~06huW5GzZikSZSZWRjZxNZEMg8ghWIH3aZVo5JUzNDCs2oxVBc4b0wdiO9Zov0MGq90pr3TCKjFzj2rg9z0~aPJheQSoVpxpYoTiiQWoxPneyh0zuiP3vpt4AeLTzPVl6NfMyu40lONF~0m~4UewTFwDUfDgwdR0DVnHnLeHX44eoy33C5j-jfNzG1PSRCSsbe5Gzt6o60~OeOHg__&Key-Pair-Id=APKAJE5CCD6X7MP6PTEA){:height 44, :width 573}
##
## ![2021_02_21_image.png](https://cdn.logseq.com/%2F7aa8ab99-753a-4230-847b-43a1c3a3ef473a19795d-cc62-4c4b-8ef5-5edb88edd8792021_02_21_image.png?Expires=4767475223&Signature=JgjRfdDH2cw7N8SOUw3rLBpG8r-E9fQrsS-8Vy1-FSBLmUogHH1wVPr0rD-um7akMCZH3CB1OJO9ZZlqEL7FuzwPRT7eUl~T093HLxb1dCqS4~Xvf4Qq3HQ2XG4izeBIV188NInRVLAr6LFAXXZJSdvW5rih8z~4Jc9CAvT3Lj6VkYxyvdGJDS5MTOyI5-Z6mZQA3jIaV1MFxawnsZqn0oyK2jM-9RMlcTQNAvzH1b0uX1aOKOCh3JjQbj~~FbpF0Oprj~xzYgigfevj0wmya7j45pDT3ZNcopEXMgGxiBRPTRYTuZpj6qH9s6E7t~qUkVnnCt-ZfvIFQ3COw4Hr2g__&Key-Pair-Id=APKAJE5CCD6X7MP6PTEA){:height 39, :width 583}
## ![2021_02_21_image.png](https://cdn.logseq.com/%2F7aa8ab99-753a-4230-847b-43a1c3a3ef47f242af6d-cc09-406c-8010-f2f08ac3d7452021_02_21_image.png?Expires=4767475401&Signature=fB~RjuG1b4fdLNfDWvlcrY9Z4KgrpozRpmgk03HzGjBlfnJ6GcXHXLuMVlFPHrjoxwRzPPJMFEPp1OhdBuS2gJFRTF5iqO4UHY98efL5pzhuyjPw7Y~ZMlKnlXHqC7hiWYWnGlyAwpq5a8xKsaLxaQuxmSFYOEQTYWkD4c3NcCfwDJOl1nXMySz~BHb1v4HRa0yq8NJc~gClKlIVbbXQ6ygr7s5m21A5sza9CvPdSTtY54oObQxdqzhYo0ccKxjzMC7tpQy9ijlVId56Q0pHA-mq6aaMjf~9Lx1Y95EkkqD0yKsUWZXoysRp9gEplZlB1mVOefbsO-xOutVm1mGaCQ__&Key-Pair-Id=APKAJE5CCD6X7MP6PTEA){:height 381, :width 571}
## ![2021_02_21_image.png](https://cdn.logseq.com/%2F7aa8ab99-753a-4230-847b-43a1c3a3ef472049d9e5-c86a-4ed4-85ce-47651751bf8c2021_02_21_image.png?Expires=4767475579&Signature=AG8LnLVvMPgoKREaqBbmygGAZr7jDSBOq~qTRef-RpEzVM57~MQ0uCj5HTapvB4aFD3eZzhycrhRurW6nmaejbo3Q~icOeiUVSFjNWXTVzafmucLQ5jEUAJMLmQfV~WmQVCg2aAm~TGXc73j0aV23tBPst0VcgSs7RnUN3utfeZqRncbyH4MiaF5dO0FA04OJTjhzUmDkdq3QukmqbnzY-ub~7MYgfSsQlg8z9jEwedAtF8MTRHkSu-ALCcbnhHUFGuPa8sXRSKDt9OCVbAC9b8p6O7rbRkqCHLrhJl-CTJhKk77b0nPBy5dwK3m3su-eDQun4zLM0VJXd9JMQL0rA__&Key-Pair-Id=APKAJE5CCD6X7MP6PTEA){:height 310, :width 560}、
### BIOS BOOTLOADER
^^**1. Linux操作系统的引导**^^
  1.1 如何从硬盘中读出的
  1.2启动的时候如何拿到硬件参数的  
  1.3Linux在初始运行中都做了什么
trap.c        trap_init()
mktime.c   time_init
sched.c     sched_init
pc机的BIOS吧（0xFFFF0bios存储的的总线地址)bootsect从牧歌固定的地址拿到了内存中的某个固定地址（0x90000) 先挂载到0x7c00然后跳到0x90000
### bootsect.s ---磁盘引导块程序，在磁盘的第一个扇区的程序（0,0,1）磁道 磁头 扇区
作用：首先将后续的setup.s代码从磁盘中加载到紧接着bootsect.js的地方
在显示屏上显示loading system 再将system挂载到0x10000
最后跳到setup.js中执行
setup.s
 解析BIOS/BOOTLOADER传递来的参数
### 设置系统内核运行的LDT(局部描述符) IDT(中断描述寄存器）全局描述符（设置全局描述符寄存器）
设置中断控制芯片、进入保护模式运行*（svc32保护模式，设置寄存器中的值）
跳转到system模块的最前面的代码运行（head.s)
### head.s
 加载内核运行时的个数据段寄存器，重新设置中断描述符表
开启内核正常运行时的协处理器等资源
设置内存管理的分页机制
跳转到main.c开始运行
## ![2021_02_21_image.png](https://cdn.logseq.com/%2F7aa8ab99-753a-4230-847b-43a1c3a3ef470e153fea-9cf8-43c1-9689-058888f2ef892021_02_21_image.png?Expires=4767478356&Signature=HFTharttCVdXrv1qPhz1jdtEFekojId5meNRsi2CpVjyfog1QXw6pBssuyDkOQU1Sst7YIXmuDpfnZNd2eel0j8dfN8r5ifNyCcKFxTtX4Lgrlbn3iN1tDPobhN8LBt9yuRcB1vmkPmoxeSaAPVQzIodX9M5jRTtvPfePzpcONwVzitfpPsGwcCmCShOMl6VkAMusafS6i341ksgI0oAnXd2uREJdLrBqtvdmLpoVwUuc1Ql5UnEHR0lrk7rVeltoVv6Qks3rUeACvGcVZx02meH9mU-U6uJ5YwOmSnrTXIRrJzAXnsNvwcJKtvaJSTTKCEpQXC0DEH3lDMxmr9mEA__&Key-Pair-Id=APKAJE5CCD6X7MP6PTEA){:height 34, :width 549}
##
## ![2021_02_21_image.png](https://cdn.logseq.com/%2F7aa8ab99-753a-4230-847b-43a1c3a3ef47551f4378-6497-4e43-b6c6-0b4e121f30872021_02_21_image.png?Expires=4767478684&Signature=e-uYRkj1OZJ3TyXd8g4Y7P~5H~VodPPv90u7Y~JpSrmANfBEeYHaRtwBhnggQSxbJx85YJyZ6hXdUG9I4mtteOXD-DgTIQB484cv0GmsaqVqH5mZkqN88xJO1TArsVrHzGrK9b4XuYV5nVROhCi32ZnFIYB1bduG9MqhwWg~VW08Au2A~Y8RHNvqq7B2khysrVe8iFPrkVLOAty~JOW~L0TWdBJqIxCQlF8EYAw6bpFMZr1GvbCR-5uDPKZwZnJQ2d5WrCmkrAbyIT67dFQZrE0FPXkEg9Pm1n-X59geQ6pzvLJyrGrpGLMXtvkSF4Th7lVw65~5CFDTx1I-WRP8tw__&Key-Pair-Id=APKAJE5CCD6X7MP6PTEA){:height 36, :width 543}
##
## ![2021_02_21_image.png](https://cdn.logseq.com/%2F7aa8ab99-753a-4230-847b-43a1c3a3ef4751a7d8c8-99d7-4dbb-99e5-6618a5197e452021_02_21_image.png?Expires=4767478950&Signature=ar5Qk5ZMc1hpDXd3pn87uOEpul-hEigPCftXxxlf~Cuw3MR~0pGU2EyWE9p~H31LVLj~kzrefNDSqxJZ5whv~MZEmHHxIZJJvBdhSL~p4ePI2zFtZf7xFzEKEeRwqjCVZzMFiScC5uMpy6dyKsFItTHQykpdHxYtJcmqv8u0~w--u4S6Jb1YW1x5Nb7WKkOjPtJXd6pxGRVgpm5SCDt3txyLKJ-rQXge1gMnvduX04kAzHvu412kDbWujx0OmSfFZ-QRMz-dFUDDlcPSIqtjyx3rQActwrrJtauh~wf63l5ZozVr2xYlQsqMIAF7tGhO-FG-6Ym2SH3dhV5eMCbdxA__&Key-Pair-Id=APKAJE5CCD6X7MP6PTEA){:height 37, :width 557}
## ![2021_02_21_image.png](https://cdn.logseq.com/%2F7aa8ab99-753a-4230-847b-43a1c3a3ef47fc720d9e-ee46-4373-8181-a286154f93502021_02_21_image.png?Expires=4767479199&Signature=UziQpXyGq3Uu1irf5qg5~gCF4CHHTCCPTRTR5zdKLxNUHp--WZr2sUf93h5e3L-RC2jaBLnEyu8~-1MghEHONWd-RNz-zN2ZKm4aR5jm9MusifOmfhpXVgp-ME1t1uMUXy84Gy2dJplmaRKcqsmuR3T8RpZIlhSPz3Pm0w~MSwsTLK5IjRYNNaHgvcBHjsNoAxsRYvHvtH8k0N8y-Ybw8hCbJrMKbtJhDH9re1hhTgyanOn6rWDppcYUpAIFKQdoKKKx4QHg0RbECpP8Momvz5ins8ogTnJyTAPgZRD75wYDqArmf2wXOoKKvaFzwKhJgXBZm62XFFB0AH-OMBmOMg__&Key-Pair-Id=APKAJE5CCD6X7MP6PTEA){:height 32, :width 560}
##
## ![2021_02_21_image.png](https://cdn.logseq.com/%2F7aa8ab99-753a-4230-847b-43a1c3a3ef4730928075-f07e-4de6-88cd-eced399dad242021_02_21_image.png?Expires=4767479725&Signature=HhRwnF0JWX2-3xr0d3mIEEk9X38RhploiJKj7KO6GElp9wKMRKNgdITYvYKSMUH8FJcP6q3Lbx9m8imlf4gm9FU3q65zWLcNQ2hjp4SJmu7MxcU4JswMDIKhkh-j~sT41y7AZcE3vhbbV8Wzn~sNS1-U14BjQuX41S3k7euPHtawHVRKLo1acSYug17WzpOfFw7ZT~rIkQydt9JJhCFTycoas3Hr5~I-f8KsJMqbceDqY0XmCApjOCl0i4W9VmnRuAjs1HEDxfxZ3XCNPXYG-QruDitsBsEULW-sEM4rxd~OsjjAV-BCT6Gb~KmTGqwlz11TMgDLMdkWaQDuSS7z5w__&Key-Pair-Id=APKAJE5CCD6X7MP6PTEA){:height 25, :width 608}
##
## ![2021_02_22_图片.png](https://cdn.logseq.com/%2F7aa8ab99-753a-4230-847b-43a1c3a3ef476671f047-a600-4490-9782-d22b775811832021_02_22_%E5%9B%BE%E7%89%87.png?Expires=4767592507&Signature=WOSOwChjNzXb0yh6r9FWNVs-yk6mYrmkGp7bZjDiSjSZnbmtCphKKdLICTw6KFPRGVDvVne8jZorPA80M1sANut6LYlEzHikdJ4iBuUjafMID5sl6HzqGdvHuS4k3t7dh8cldxrgTMJrJfOhvGcr9lg8v2fDft2pD75pLsr9cvsGjZK-5hfd5JgRqg6yniIICIZ4iMT0Y3ALc2QxrC3fbG9BINMvICMYDnw7yrrj6TEHyh4PQ0HpIy9Z9wSWhX8-z2jxgHXDVZhJ4H90hWP~MaiKOOs~ZtJxbiVpA8CMFilb4rMzy154DtrV62SJoxfGF1VZX6IdzBTFUFlgz8T5JQ__&Key-Pair-Id=APKAJE5CCD6X7MP6PTEA){:height 19, :width 607}
## bimap.c ![2021_02_22_图片.png](https://cdn.logseq.com/%2F7aa8ab99-753a-4230-847b-43a1c3a3ef47ef962e94-e422-494a-88ad-4e78c41af9402021_02_22_%E5%9B%BE%E7%89%87.png?Expires=4767592779&Signature=JGXWUgOAHaIyf0Qe~cu6gWI42uIuc~IAemSRG2zXUe09TME2-7xCImVlk0vpZUCGx9Hz5r~eudmMd~8ji5fKLNCj9MkpEl1ux439vqBTB5mYHhMBtLpkQsWwe7360KWnLL7M9WF55q8afW8SPQ~7YBdKFx6Ahus01jfr77uMkr-N8qBx5S~qVz7--jeMtx6HIpZTetoe8YKXs1queHodJX2~Eah78y4qbxw5ufcXw4bjytQz38HECmm2Nydeaviwx93GlL~KXFuC2DxqFULrAvv19OWUMrPD9CWJPB9zBSdTu~kqHoRFoKKcSf8EoFR3E~3pwML2nBSNJETGxt1OEQ__&Key-Pair-Id=APKAJE5CCD6X7MP6PTEA){:height 21, :width 588}
## ![2021_02_22_图片.png](https://cdn.logseq.com/%2F7aa8ab99-753a-4230-847b-43a1c3a3ef47ccddc5a6-b32b-490a-96b7-889bb3d9443a2021_02_22_%E5%9B%BE%E7%89%87.png?Expires=4767592756&Signature=LlKbGpaOzh7NKaZxaJwuF9DFYEzifRGt~4rFLwLJjD73Aycv3r~bXtoILEL~8c4xwnic6iWhfe3ClDSYZffWepkpRAojZc74JRs7EwHl~Lx0zhEwrcwqfl~8GmNmUmabPc9D~YwjDKDRkaeRAeLMdhCtUURxlGKmyzYI2uN23jkzkQLdXsy5e7PA3hsAHaI4Sepaf3gO4szj4sWNwUdOnJuy1ur~10A1tnpxdyOOhfoewUc4x61cvfj6EmDkEHlkU13j1d9Hym6TMbUewg1nwTgR6p34kYsZHWkr4c6xSy-OeD1-HKqJNk12scvAcEsXXohWUSYmswpsvJFX2uoT8g__&Key-Pair-Id=APKAJE5CCD6X7MP6PTEA){:height 23, :width 512}
##
## mount unmount
## 操作系统中的一个超级快数组
## ^^吧需要挂载的设备文件系统的super_block读到高速缓存区中斌放到超级快数组^^
## ![2021_02_22_图片.png](https://cdn.logseq.com/%2F7aa8ab99-753a-4230-847b-43a1c3a3ef4730f4c71a-08e8-4312-bb74-0fa4e647ae702021_02_22_%E5%9B%BE%E7%89%87.png?Expires=4767595215&Signature=MTYeR4WJUo8FmazzAPCorXK0Z2OzdemLF73C2-kGlIR6MufRjJgY1s7nbapfJmggHWKztAfa3dbtoLIAOWuaQjlEehNIFn7Bt9hxNbDKp4diQhFhykDgtnaTAqjdxhSHpcZ02qM79U9bk4qCsWORRLk4FQ1TSEO8MZYr2BICHBpZ5yhYwRz7frxGWAkNJD06swpwKJMB2U8S5zflc4BZtk~41BYc3BrNtcXw1hS1tfoOf13TOUmKUXv7LqRshjtW9qnQv2D1E1azZENOlw~hFOL6nMQAW3BeN7qyO-LUTKS2mmRiH9MD1DTF57aVXlZAU7W5CvqfcZU6YalDUfdxdw__&Key-Pair-Id=APKAJE5CCD6X7MP6PTEA){:height 25, :width 467}
## ![2021_02_22_图片.png](https://cdn.logseq.com/%2F7aa8ab99-753a-4230-847b-43a1c3a3ef47afa9ff4d-19df-41ab-a27b-1c1c677749f82021_02_22_%E5%9B%BE%E7%89%87.png?Expires=4767601523&Signature=hvoxdn9jlAahthnlPF~U53TYl6-a0be3mDs8RsiBx-FpBgBP9ddp2MPgyRc8BT59p1c12h9XqOnVcwpFANSvzYa56qjZeFqBvd0C03xYmxGSMZzi38eqhIxvyN8FMrrfd3MkacIbsYNZO5a2fZtLz6~FDChDfXoq~4pZ78EVuT~t1-VBNOcB7rvg36dwhRVx55pSVWXkEHg~eUEUUaos1Xmsj3evPvcyiVdunAo~qv8t6pG4ejCLk8NEIymM5bCk8X5uvF3N9CQtGX2d51fAN2UGVA~OupJlEBrPLa7uiS4N~dnyQ2y4QI45txi4-cawZNI8ibONK8EZFz6c17GhhA__&Key-Pair-Id=APKAJE5CCD6X7MP6PTEA){:height 36, :width 463}
## ![2021_02_22_图片.png](https://cdn.logseq.com/%2F7aa8ab99-753a-4230-847b-43a1c3a3ef474425f27d-2d08-49c6-85dc-2de330124db12021_02_22_%E5%9B%BE%E7%89%87.png?Expires=4767601689&Signature=nDjsUFQPThdS64r2FiWDmcXlp6xdRvk-hm9RNYJ75DPDtgYkJZ9KOO~TXy7Vo-Ae2gIH~03Sy2WubOklYvYYjiKYreHfz3mgo7MVay9cfzWQrrWEg16Z2166~m5RlSOYvyVcFNjO0VstYw0-q06aAIXWgM1NRGWADj7u1Z~bWyRz8EQ3PaIsYf0gm5HZjkD1-tkQLU5VIngxvNU-i3UvaqqJY3MxTHRyL-0YXUG-IowfMPJVjIZKRldwqMjYfeAFKBEaqYt~d3vkOh~v3hm8Py8PiCORDoiLjKAoS5dk5xfUsoOH7Iv8w1zUc4FmSDNk0VSpxDcHaBkh2IHsrJydfw__&Key-Pair-Id=APKAJE5CCD6X7MP6PTEA){:height 29, :width 427}
## ![2021_02_22_图片.png](https://cdn.logseq.com/%2F7aa8ab99-753a-4230-847b-43a1c3a3ef47d3ac04c5-6b9f-48a8-b228-83bc798ec4182021_02_22_%E5%9B%BE%E7%89%87.png?Expires=4767601763&Signature=f41QMINLpppF1l3XIjxnpBbyWtxkNYWpiv8cK9ibQ6Cl89XXyNUi4gYGhVaD3hu5h3MjQzk5DFePxmS95qk0RRffZlYpsua4dnl6~IUwIlWHxaLDmN7bqJ1~ow3PXaf6rfENo4lB-OEmtT8mhWJhYwjpqhXZTN6HJkD1usynY35a5Nl4kVcfA2lNqKzZYo6XBneFrlLdDCzkwurAaqXCzPnZswUpOAks6eYSI8Ic9g1L05QfpWlOTfS5ixEpeFcUo2yCBzx6tmVToxzX1qWOj6SdhEwWnek6MMoleGVjKO6rvsg~jJ0jcZa1OffKP9kedFbGcXivDHgWvNyyzh972w__&Key-Pair-Id=APKAJE5CCD6X7MP6PTEA){:height 28, :width 431}
## ![2021_02_22_图片.png](https://cdn.logseq.com/%2F7aa8ab99-753a-4230-847b-43a1c3a3ef4714e64854-a22e-4586-a0d3-8017a4887c572021_02_22_%E5%9B%BE%E7%89%87.png?Expires=4767601985&Signature=j2IlsC0ENBuiPd7yX1OfL0B1hhxhjt9r3xz2rWyMtFHvo9s5yiQohBtEOkqzxaYEF~o14d7hYQH-E5s~s3ND6NipfM4KDI3~bTcgWgr3j-oBdukV7VWTmrEfHvmq-7UQbqRxod2lZYhyWafHZ7iq1p4kIQV-5qD2OCXzWKR5Ro2TmQtwswO7DgzI1JPcyZ2DDNoR7eQf92A7JDnwahOn4aDLd8-8fedJ2H3JUcBxlkXsbJIULOdmpdzad84KETweZyy~7EJVTlURT-dSUtxGE8sKGUIYVcs79MRp-lASXFV7PXU7Q~KSGev4PHwktqKqi6b9TTCGGdFURAQQ4BcRfw__&Key-Pair-Id=APKAJE5CCD6X7MP6PTEA){:height 23, :width 431}
## ![2021_02_22_图片.png](https://cdn.logseq.com/%2F7aa8ab99-753a-4230-847b-43a1c3a3ef4776541c00-04d2-4919-b0a9-7085d0a3bb612021_02_22_%E5%9B%BE%E7%89%87.png?Expires=4767602063&Signature=M6akKkEW0eHIWSUb0pfBZPzt~hIBJI9EIVw6GLKog9jNXdN6d9Dj2Rz~RcAscLGfiwxb2JeKjP4CeCPXViETSLiAeuiaCPhbPlv34uryFEEbmKoTj9mXfPQQPZbKtCiWEdAidPkkr2zFeq9TPR9-5mGtQ1XrOvpAvF67fiGEGxRZwqLQ-~O2KDmWGWNY5iaq3524pyDhV5fqi2uUSli4o0DJhR6JH4carS0DBhGw5ffBuN7DQFqOZVBa298vYnM5z4i7K5gGB-YHk4d~Z4K4I-7cwy1tK-I9YOLlshkLH0bCpgbHPJVsz6X8VS3pRhX8O4BFRYw0wkWAmPI-V0cJlw__&Key-Pair-Id=APKAJE5CCD6X7MP6PTEA){:height 38, :width 433}
## ![2021_02_22_图片.png](https://cdn.logseq.com/%2F7aa8ab99-753a-4230-847b-43a1c3a3ef4705548eff-ff11-4dab-800c-09bfd49767872021_02_22_%E5%9B%BE%E7%89%87.png?Expires=4767602412&Signature=M86WcFHhFEFLnfgf9CX1sk~qDA~qYx7-NE~Bwa4lw5yuOlSOinrT2WqXlh6M9ofz109~Xl939Dmkzki~PnXW2gvAcnNEH6OYPY6QZtg38zKY7yA3FMRdpXwHIDRRAAxmwBs~NMnnMww8cLjrAI8YwkuWVv-mAadvHGgvtFUSHqnaz0Lxd7ZqZMhb3XVJc5PcvZRJNJmCo8kSUwOTBWuIihhAmRy1kRgy~759WXfk3QOeUK1es82myTzVSTVeoteFYWGYzlFJ5kI5jzKkNS6DaIQdFMBtcSajWST8gO6khT2goBknJlz~hw7tlQSEBN5Jj4-tbmhbyoTFMe7I8MzPlQ__&Key-Pair-Id=APKAJE5CCD6X7MP6PTEA){:height 161, :width 471}
## ![2021_02_22_图片.png](https://cdn.logseq.com/%2F7aa8ab99-753a-4230-847b-43a1c3a3ef477bfbc7ff-8d79-4797-8da8-f9a454dee69f2021_02_22_%E5%9B%BE%E7%89%87.png?Expires=4767602581&Signature=YxiY~NpbOCjdQ-v8pvilcutfgTyR4MrQFs6eT58JRN-5xOmy5PMtWDpRpvtAlKLHGO7kcVAHvpE6e-TPqmYbwMS-23EwlrGXmk9f~wnxOLV3SSX9cJ7Woq~4KIrIvXFhPrmE9JHVtByVmJ7VBj6Bi7-GSgaQgjVK64qgf1fSpln3rWu2S~ZgTl7LMcdGGxu00-3qiXOb05sTaDupmDVDjobWupKW8xvn4~yV8gH-2-682wo3iTuPEmACcX-VqksOV8i5gWWSV5DzSaxo8HoL1IZl1uKU5prX80hhRahTzKiaq~bKNiZaBiuN37m8TAPO19MxRidYx7f4N9CeTbqSPQ__&Key-Pair-Id=APKAJE5CCD6X7MP6PTEA){:height 410, :width 626}
## super.c**super.c**
## 1.对设备的超级快进行操作（获取 读取 释放）
## ^^get_super put_super read_super^^
## 2.超级快是设备文件系统的映射（代码中的类）
## 文件系统的加载/卸载 mount unmount））
## sys_mount sys_unmount
## 3.根文件系统的加载（ /  ^^linuxrc^^）mount_root
## ![2021_02_22_图片.png](https://cdn.logseq.com/%2F7aa8ab99-753a-4230-847b-43a1c3a3ef4701fc4c75-b40e-4164-a458-02587260e2562021_02_22_%E5%9B%BE%E7%89%87.png?Expires=4767604016&Signature=JhTjSFAMS0a0z4nwVxs7kRbITFyCMEMtq5UkjKIbUSsHXVXdUVb6Ql23uGT4dkl346xtZlnHXBlhZGVj7g3NhnvqHZ8rn~YOxt-ST814UXKF0fn1NqVCfc79TyzkVXg5fLnRzD2EWSzVArW2OsIDWgBIo-ZrAtng3s0P8Y0hrXo6uD0w63~Wz2UhAsk1fV3pRZDi14RNn3f8fnpLIKajtW3v8P-oBXKSncq0yUzVaIuHUYn4OdUntiA7bXsHADBqarP9taBPYjQRdD5JJuwMpuOCibv0X8P1fYQoppyL8DMwq2Ud0MLzdknQSvWgPy-9lykViYZDP8bEdOkgIoZiEw__&Key-Pair-Id=APKAJE5CCD6X7MP6PTEA)
## ![2021_02_22_图片.png](https://cdn.logseq.com/%2F7aa8ab99-753a-4230-847b-43a1c3a3ef47a71199e5-303f-4f2c-bb25-2ccc83eb6eeb2021_02_22_%E5%9B%BE%E7%89%87.png?Expires=4767605042&Signature=CFAa9UQYQ8H46vlXNUVU7hFEApzhRgNQb~H-~I6tBzZwMwP6VfpfzuHvzl-Dl85TyAssFpS14Y4KqX9mI3mUOHY4afDLBhjVQNBGrnwoCs2o65sUAwR2kiqNqRq-9ISIHuZsw~F6nreyHdRjQqifZKOfALPEbv7V8pQEM7eLwfqk58KjL9pStRYIdppS3vJBMvHYBH1wUmJmsAagHcteH3xcA3J7H5bmgWUt51VayO9vyWPKWkWSvnPi5ALRyuxpsuOgsmmwmJcsD9bhr5QLYV9o0krS-WKaAznTgePF1laQFJsWuPoMP0DcZLCYkEMX6bcR7PnGNttxqL5n2p1aCA__&Key-Pair-Id=APKAJE5CCD6X7MP6PTEA){:height 365, :width 626}
##
## ll ![image.png](/assets/pages_linux-kernel_1614050273379_0.png)
## ![image.png](/assets/pages_linux-kernel_1614050146009_0.png){:height 338, :width 626}
<<<<<<< Updated upstream
## ![image.png](/assets/pages_linux-kernel_1614051774951_0.png){:height 222, :width 626}
## ![image.png](/assets/pages_linux-kernel_1614051779845_0.png)
## ![image.png](/assets/pages_linux-kernel_1614051790027_0.png){:height 187, :width 626}
## ![image.png](/assets/pages_linux-kernel_1614051796486_0.png){:height 302, :width 626}
## vfs fs 文件操作系统 大老板 ![image.png](/assets/pages_linux-kernel_1614051826684_0.png){:height 315, :width 626}
## ![image.png](/assets/pages_linux-kernel_1614051834346_0.png){:height 393, :width 626}
## ![image.png](/assets/pages_linux-kernel_1614052002172_0.png)
## 存在疑问：mtime创建时间 ctime修改时间
:PROPERTIES:
:background_color: #497d46
:END:
## ![image.png](/assets/pages_linux-kernel_1614052141947_0.png)
##
## ![image.png](/assets/pages_linux-kernel_1614052416103_0.png)
## ![image.png](/assets/pages_linux-kernel_1614052633067_0.png)
## ![image.png](/assets/pages_linux-kernel_1614052667942_0.png)
## 输入 输出 错误 3个标准
## ![image.png](/assets/pages_linux-kernel_1614052795077_0.png)
## ![image.png](/assets/pages_linux-kernel_1614052847222_0.png)
## ^^系统调用 2e软中断 sysentry^^
## ![image.png](/assets/pages_linux-kernel_1614053669097_0.png) **
## ![image.png](/assets/pages_linux-kernel_1614054023327_0.png)
## ![image.png](/assets/pages_linux-kernel_1614054403213_0.png)
## ![image.png](/assets/pages_linux-kernel_1614055394828_0.png){:height 543, :width 626}
##
## ![image.png](/assets/pages_linux-kernel_1614056377803_0.png){:height 296, :width 626}
## ![image.png](/assets/pages_linux-kernel_1614056791558_0.png)
##
## ![image.png](/assets/pages_linux-kernel_1614057332281_0.png){:height 287, :width 626}
## ![image.png](/assets/pages_linux-kernel_1614058083375_0.png)
## ![image.png](/assets/pages_linux-kernel_1614058469049_0.png)
## ![image.png](/assets/pages_linux-kernel_1614058637281_0.png)
## ![image.png](/assets/pages_linux-kernel_1614058684494_0.png)
## ![image.png](/assets/pages_linux-kernel_1614070563175_0.png)
## ![image.png](/assets/pages_linux-kernel_1614071430467_0.png)
## ![image.png](/assets/pages_linux-kernel_1614071765038_0.png)
## ![image.png](/assets/pages_linux-kernel_1614072083425_0.png)
## ![image.png](/assets/pages_linux-kernel_1614072201776_0.png)
## 用户态切换到内核态
## ![image.png](/assets/pages_linux-kernel_1614072726632_0.png)
## ^^fd -- 文件句柄^^
:PROPERTIES:
:background_color: #497d46
:END:
## ![image.png](/assets/pages_linux-kernel_1614073531070_0.png)
## 逻辑地址： 空头支票
## 虚拟内存概念
## ![image.png](/assets/pages_linux-kernel_1614074149519_0.png) 】
## ![image.png](/assets/pages_linux-kernel_1614074308689_0.png){:height 382, :width 626} 逻辑地址映射到物理地址，^^内存一页为单位存在 一页4k^^
## 提供给进程远比物理内存大得多的内存
## 有效管理物理内存，病把零散的内存也映射给完整的虚拟内存
## ![image.png](/assets/pages_linux-kernel_1614074557028_0.png)
## ![image.png](/assets/pages_linux-kernel_1614074811508_0.png)
## ![image.png](/assets/pages_linux-kernel_1614075008599_0.png)
## ![image.png](/assets/pages_linux-kernel_1614075315933_0.png)
## ![image.png](/assets/pages_linux-kernel_1614075456599_0.png){:height 334, :width 626}
## ![image.png](/assets/pages_linux-kernel_1614075488702_0.png){:height 273, :width 626}
## ![image.png](/assets/pages_linux-kernel_1614076330733_0.png)
## ^^4k -- 12位^^
## ![image.png](/assets/pages_linux-kernel_1614076380709_0.png)
## ![image.png](/assets/pages_linux-kernel_1614077159891_0.png)
## ![image.png](/assets/pages_linux-kernel_1614078422082_0.png)
## ^^windows蓝屏一种进程^^
## ![image.png](/assets/pages_linux-kernel_1614079295450_0.png)
## ![image.png](/assets/pages_linux-kernel_1614080372160_0.png) 一个页目录项---4 int
## ![image.png](/assets/pages_linux-kernel_1614080404602_0.png) ![image.png](/assets/pages_linux-kernel_1614080516381_0.png){:height 462, :width 626}
## ![image.png](/assets/pages_linux-kernel_1614080606744_0.png)
## ![image.png](/assets/pages_linux-kernel_1614081202777_0.png)
## ![image.png](/assets/pages_linux-kernel_1614081387836_0.png)
## ![image.png](/assets/pages_linux-kernel_1614082497051_0.png)
## ![image.png](/assets/pages_linux-kernel_1614083377060_0.png)
## ** ![image.png](/assets/pages_linux-kernel_1614083517242_0.png)
## ** ![image.png](/assets/pages_linux-kernel_1614083684081_0.png)
## ![image.png](/assets/pages_linux-kernel_1614083849411_0.png)
## ![image.png](/assets/pages_linux-kernel_1614083870477_0.png){:height 511, :width 626}
## ** ![image.png](/assets/pages_linux-kernel_1614086452565_0.png){:height 394, :width 626} **
## ![image.png](/assets/pages_linux-kernel_1614087209717_0.png)
## ![image.png](/assets/pages_linux-kernel_1614158801258_0.png){:height 323, :width 626} ![image.png](/assets/pages_linux-kernel_1614166671650_0.png)
## ![image.png](/assets/pages_linux-kernel_1614166378503_0.png){:height 318, :width 626}
##
## ![image.png](/assets/pages_linux-kernel_1614166485814_0.png) ![image.png](/assets/pages_linux-kernel_1614166626774_0.png)
##
## vscode://vscode.github-authentication/did-authenticate?windowid=1&code=5cb2b80308350ef16efc&state=dd83f6fa-4b1b-4609-b23b-7b4f583fe4f6
=======
##
## VFS FS
## ^^文件操作系统是个大老板啊^^
:PROPERTIES:
:background_color: #978626
:END:
## ![image.png](/assets/pages_linux-kernel_1614051064149_0.png)
## ![image.png](/assets/pages_linux-kernel_1614051195767_0.png)
## ![image.png](/assets/pages_linux-kernel_1614051289931_0.png)
## ![image.png](/assets/pages_linux-kernel_1614051296603_0.png)
## ![image.png](/assets/pages_linux-kernel_1614051559568_0.png)
##
## ![image.png](/assets/pages_linux-kernel_1614051638316_0.png){:height 218, :width 610}
##
##
##
>>>>>>> Stashed changes
##
