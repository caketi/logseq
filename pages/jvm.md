---
title: jvm
---

## ^^JAVA,类型的加载、链接、初始化--->runtime^^
## 加载：查找并加载类的二进制数据
## 链接：验证（确保被加载类的正确）、准备（为类的静态变量分配内存，初始化为默认值）、解析（类的符号引用->直接引用）
## 初始化：为类的静态变量赋值初始化
## 类的使用：首次主动使用 ^^7中^^new, 访问类或接口的静态变量，赋值，调用类的静态方法
getstatic putstatic invokestatic 反射（Class.forName("com.test.t") 初始化一个类的子类 ![image.png](/assets/pages_jvm_1614260950025_0.png) ^^都会导致类的初始化^^
被动使用
## ^^类的加载--.class->内存-运行时数据区的方法区中，内存中创建一个java.lang.Class对象（封装类在方法区内的数据结构）^^ ![image.png](/assets/pages_jvm_1614261161716_0.png) ![image.png](/assets/pages_jvm_1614261422811_0.png) ![image.png](/assets/pages_jvm_1614261819295_0.png)
## ^^final 常量--->类的常量池当中^^ ![image.png](/assets/pages_jvm_1614262072348_0.png)
## ![image.png](/assets/pages_jvm_1614260024725_0.png){:height 370, :width 626}
## ![image.png](/assets/pages_jvm_1614262428015_0.png) ![image.png](/assets/pages_jvm_1614262973414_0.png){:height 370, :width 626}
## ![image.png](/assets/pages_jvm_1614263249004_0.png) ![image.png](/assets/pages_jvm_1614263396865_0.png) ![image.png](/assets/pages_jvm_1614263634984_0.png) ![image.png](/assets/pages_jvm_1614263648460_0.png)
## ^^当一个接口在初始化时，并不要求其父接口都完成了初始化^^
**只有在真正使用到父接口的时候（如引用接口中所定义的常量时），才会初始化**
## ![image.png](/assets/pages_jvm_1614264630030_0.png) ![image.png](/assets/pages_jvm_1614264731106_0.png) ![image.png](/assets/pages_jvm_1614264935131_0.png) ![image.png](/assets/pages_jvm_1614264951467_0.png) ![image.png](/assets/pages_jvm_1614268993393_0.png) ![image.png](/assets/pages_jvm_1614269078750_0.png) ![image.png](/assets/pages_jvm_1614269088892_0.png) ![image.png](/assets/pages_jvm_1614269117853_0.png) ![image.png](/assets/pages_jvm_1614269131344_0.png) ![image.png](/assets/pages_jvm_1614269172304_0.png) ![image.png](/assets/pages_jvm_1614269184522_0.png)
##
##
##
## ![2021_02_20_image.png](https://cdn.logseq.com/%2F7aa8ab99-753a-4230-847b-43a1c3a3ef4797c840bd-c3e1-49cc-970a-4b9827da75422021_02_20_image.png?Expires=4767385989&Signature=UwomT7eWMKO28zVNEkObg4AI4Q0J15iUfiaVOtDxJNU7jKldcIfxnBqaWkg6BdYMLBseIty1QCdx6BTJS5johjPYqEhkiBdZs9i0vDkR7WgNHYLbttOcIglP4l4WChvnAF2l3zQACLz82SNNi-du6cHk42ZXd6wepNU1jQyyvcoBQaB2Q9BfUIlxc6xK7nJ9OWLVcTTNwhdwp7D~hIfiGW69eiGdZWTA1Mu~ZczRHOLrtTkZjdbg1VqTxCF-UyLxcRBcT88B3KY2PJVVZ4BoOcYAcWuDWlWcEvk2UUqRdbLG9-tswSk2VMg7skxDgKAnRLAupNO2jPPgfpmEv-d0WA__&Key-Pair-Id=APKAJE5CCD6X7MP6PTEA){:height 193, :width 295}
## ![2021_02_20_image.png](https://cdn.logseq.com/%2F7aa8ab99-753a-4230-847b-43a1c3a3ef47c72c2622-9ea5-49d4-b5d4-b7b47654e34b2021_02_20_image.png?Expires=4767392525&Signature=kpyVeXDOo2bzHp2oUagRcg2Nwg2~WjMwT3WLKGtXEYU4E-XTdsBckFLHf3jVQhdRK5gJ11l9Ee0jDBRNaMQgItOHleEpZfG~pfhIdOYGTA5Ub2ybVVKFLtzG0ZvVgZjPYRvnjGQ9QBNdRKa~975skP8h8~mmhSN7nx689OXwRYa53l2j4qCgQe6GQv62x9gAbBAL3B3~NK3gZGG5oWRfHFZMF9IErQg6VLf3kJpt-RrC40o8X43AW9D3n-AbdMWSsfkPs2P831IB0jPJMrDI0UxSkbhvRLDfgCe6cl69conrZIiedBWSfQI4VcM-WeL2k9PU8b6vCLsTCx48iIFcjg__&Key-Pair-Id=APKAJE5CCD6X7MP6PTEA){:height 129, :width 310}
## ![2021_02_20_image.png](https://cdn.logseq.com/%2F7aa8ab99-753a-4230-847b-43a1c3a3ef47b07fc96e-0461-4dc0-974b-db145855f4082021_02_20_image.png?Expires=4767403581&Signature=VdzrpAhIt3U2MKCXj1kOTWproymRSqp3Ei8fas15UjyZVOkWEm7jld9lYYHDMBERO6fJREhC7fGgUYsBo-83bPgcKNQfyRMbEXt0uVLZmDR-Oeu64t9DKxVdREeZqirrfy6aZ~cDNpIMPQvMYbQiRmSn--sLx9ejYP5Mjsi4EU9qTcWEF5H4twkmVGW7lSL1CNuc-5JakAUBZ13FGMCVM2qa3tnEJxdUX7PHTzp2hG7VyUq5b4MyVk4uxs92b295dCMP8~JpdXQRk2Zx0I7DzOiVs~7FfrL5KZXVGkD7d-SSJsQizPJmvF-Jx5r2G~ompG5dBZNs9tT2eKp4o6R-dg__&Key-Pair-Id=APKAJE5CCD6X7MP6PTEA)
##
