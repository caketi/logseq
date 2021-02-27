---
title: final域重排序
---

## 写final域的重排序的规则禁止吧final域的写 重排序到构造方法之外
java的内存模型mm 禁止编译器把final域的写重排序到构造方法之外
编译器会在final域的写之后，在构造方法执行完毕之前，插入一个内存屏障StoreStore,
保证处理器把final域的写操作在构造方法中执行。 ![image.png](/assets/pages_final域重排序_1614390523267_0.png)
