---
title: bit-packing
---

## ![2021_02_02_图片.png](https://cdn.logseq.com/%2F7aa8ab99-753a-4230-847b-43a1c3a3ef47463202ea-bdcd-4c3f-b4d7-f0db121a28e62021_02_02_%E5%9B%BE%E7%89%87.png?Expires=4765839378&Signature=OLruzm-3EDr1BT7CAnB49EXMNNfEBe2wf~gq0yDSr11mg0qn5wKHwxJyxpD6xSf3Fhe1tXKtVazeVOiY1uRD5wNsaZMLc~grIcSYje6GCI~jhcieDbyXCIcYY2QxY8SXr7GuPu2Qo~Yhub1QYduaqL6Sn~-9iL~XwMCjpbtVeXck4XUtXOd5DEoxpjIT-wo98y7gXHLHJxcFGSoTUtnkopHZUTLY-AxFTfDG09Ae7c6r~PVZ9DRG54~fXxxxqfAtZXaOaaO1NSwz5C49B6YEVBmhoih54ttsDyaWagJKMdvp4Ip~~TFShnH82lMgQ9lRqbafB5yWXtavXEcIqE2SoQ__&Key-Pair-Id=APKAJE5CCD6X7MP6PTEA)
## ^^Bit-packing is a simple concept: Use as few bit as possible to store a piece of data. ^^
## [](## [https://www.kinematicsoup.com/news/2016/9/6/data-compression-bit-packing-101](bit-packing101))
## often compressing text files to 30% of their original size or less.
## games. Images, textures, geometry, and video
## **The most basic tenant of compressing data is: Don’t store bits of data unless you absolutely need them.**
##
##
##
##
##
##
##
## extracting <length> bits out starting from <bit> as a separate integer
## oh so like.. starting from bit 5, extracting 7 bits, if
your flag is like...
11010010101100110
it shifts to             
00000110100101011
then you grab 10000000-1 so
00000000000111111
and & you get
00000000000101011

I see. that's cool. what are you using it for?
## 变成32位吗？
## packing less-than-32-bit integers into a single 32 bit integer!
## ![2021_02_02_图片.png](https://cdn.logseq.com/%2F7aa8ab99-753a-4230-847b-43a1c3a3ef47206b7cd1-d511-4668-8076-9a09a68662a02021_02_02_%E5%9B%BE%E7%89%87.png?Expires=4765839745&Signature=E8SkNoDkCOxtkXfC1j-hlAJRXq64a3wxakbddXuzXtkD75nrK7jBcrIvcQ-~xWdQRBIUbjujsGpvlLqQiHf~XTVpZSRCLgH9SXAyT2mAafjb0A~8CZdRiCiFfNwXBEAQQ5RMXgUrJ9jc318eY-aD7VAuY8uW1beBMY5YuwkM2ezrSm9pc71XEiO1rpEfy-U6L-LYQjHnXKPXwm8h6iHkOK1B8~hdjhFW63oPcAbTHarLFhJa~SjF6D7vH2Z-TQkVOc2hzMRMz0p6umOOhLWVJY9Ea41AeBhTLvTz9O5wMIp2n7Q8IvltJjAf4hamU8CdEsNMtuoKJhFTWsyXlukZsg__&Key-Pair-Id=APKAJE5CCD6X7MP6PTEA)
## ![2021_02_02_图片.png](https://cdn.logseq.com/%2F7aa8ab99-753a-4230-847b-43a1c3a3ef4799f31189-2f58-4b22-947a-94a805df6c842021_02_02_%E5%9B%BE%E7%89%87.png?Expires=4765839767&Signature=BkYPw3N308ZdXg6uHmY90AApYnaEiap7au4pAaguqmV4WaFk0pO3ATIWHsrn4Jgw8SrrZ8KwwzlKR8B~2FKx8ba6m3xCNmTDAZHQcjxXXJI02SIebATUywk3M1yxvwqTmtKWU5cZ5WhBg1aFIFLef-m6DA1BzcXjrmcMyMms1IW7nfSzAwj4ewsdI1aTTKY52Ywnom-e0ntaHRzz5IOxRLdeKQ66TV6z3brtwbldWuVVgJs9wDhBiZrxAg2xDS4ikoEk~kpKL73Oh9OK6apskfYbdRCOUJuUcyQ5Wb8jlkymMLFDbdH0ELpw~LgdwtT~jXdeY6VmPnK~2UdqW6~g7w__&Key-Pair-Id=APKAJE5CCD6X7MP6PTEA){:height 147, :width 475}
