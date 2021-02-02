---
title: bit-packing
---

## ![2021_02_02_图片.png](https://cdn.logseq.com/%2F7aa8ab99-753a-4230-847b-43a1c3a3ef47463202ea-bdcd-4c3f-b4d7-f0db121a28e62021_02_02_%E5%9B%BE%E7%89%87.png?Expires=4765839378&Signature=OLruzm-3EDr1BT7CAnB49EXMNNfEBe2wf~gq0yDSr11mg0qn5wKHwxJyxpD6xSf3Fhe1tXKtVazeVOiY1uRD5wNsaZMLc~grIcSYje6GCI~jhcieDbyXCIcYY2QxY8SXr7GuPu2Qo~Yhub1QYduaqL6Sn~-9iL~XwMCjpbtVeXck4XUtXOd5DEoxpjIT-wo98y7gXHLHJxcFGSoTUtnkopHZUTLY-AxFTfDG09Ae7c6r~PVZ9DRG54~fXxxxqfAtZXaOaaO1NSwz5C49B6YEVBmhoih54ttsDyaWagJKMdvp4Ip~~TFShnH82lMgQ9lRqbafB5yWXtavXEcIqE2SoQ__&Key-Pair-Id=APKAJE5CCD6X7MP6PTEA)
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
## packing less-than-32-bit integers into a single 32 bit integer!
