---
title: css-tips
---

## CSS Quick Tip
## So - you've been given the logo file, but it's a jpeg and what you need is a transparent png!
## Ideally, you get the correct file Rolling on the floor laughing But in a pinch, you can use `mix-blend-mode` as shown.
## https://codepen.io/5t3ph/pen/ExNaopW
## ![2021_02_01_图片.png](https://cdn.logseq.com/%2F7aa8ab99-753a-4230-847b-43a1c3a3ef4705bb5fd4-4e7a-466e-ad45-1c2e9add86f02021_02_01_%E5%9B%BE%E7%89%87.png?Expires=4765787082&Signature=B3MmJuXB8XID66~qBk8aZNCcOX8DSiU1-J089dHvIxI7QVTBD5tRDMAC0HYebXU7pvmG1maRBPQepPwuRdkER-~RaRDuncVM0BVvnbh9J7-Fb3JWgOLFCnKaCGTO2gp02NjzKxINAM1ofWzamg-RwKVkZSUFVO2jtioaDV1GDHSuCBI8yohShinF8n8qLJKRxwDWUkPg7ZqDlN2ixluoMqvC276gp4WC-V4XjKeEU2P1rGMsUVEdwWCI-mtzDQIhroGC6J9IfhblmIJnmwlNR0Y5fg1-KBALS5-FTYLQIpK4L3Tntx0j~K-zvWqi~I7voQ4aZToiypsga5zvsYFogg__&Key-Pair-Id=APKAJE5CCD6X7MP6PTEA) ![2021_02_01_图片.png](https://cdn.logseq.com/%2F7aa8ab99-753a-4230-847b-43a1c3a3ef4740b84626-06be-4415-979b-1473a22b9e072021_02_01_%E5%9B%BE%E7%89%87.png?Expires=4765787093&Signature=TNcvu~DwTqyQ20RmyG8cLTo4ltSJrlDTfSkM0d5MLRXAGa2CxsZ9f-L1vNuOFh2G3DH0J6yLKItS9dMauKOIzJjqg5R3NSDQ6GfF3tOo1GF9uobv3kWJBc7t7DpPSJtDelOtxyy7G0IzCkpq8XdAH42qqSawGWWdjhuuPyRR0dfhQfOs2nMLLkNbixg-hibEwtJ6CoKlw9Ni9-qqvS4AgHVJQHSRxDpxpRLusUwB-Az08UfQNF1zaukOa-ZNtPFRxjP0hEOqX-8~Qgy~s-2jpNLBTxUOfDzZPR18VwkTfaQ7dtqBnf1NW7~yRx38~kvmdj5lIClEIoOVMEEX2MWXvA__&Key-Pair-Id=APKAJE5CCD6X7MP6PTEA){:height 344, :width 626}
## An easy way to have a fluid typography(font-size changes depending on the screen size) using only the 'clamp(min, val, max)' CSS property : Star-struck
## ![2021_02_01_图片.png](https://cdn.logseq.com/%2F7aa8ab99-753a-4230-847b-43a1c3a3ef47ab629a24-e282-48ed-be10-740df759828d2021_02_01_%E5%9B%BE%E7%89%87.png?Expires=4765787536&Signature=DqEU-lz1t-G5mDptXESauUFF2zWAfq7YVI30nFovmOBUcvjx8A7MjUF6mW5f9PO4JnRXU68owokytjhvZVdGUJIAzldvFy2mudi1uVbW~6ahrzjEz2Pu95ZeI1T3h-1Ka8KJOavbEB-8TlIQrfD2uy2gfhSLN5QHnz1DT1QIzTYCBzvQCFgaxsl3u8t1y2Rw3FFiKsKYmtjxs1IDwWxmFfwncJmsh9~Ktg1Tv1KieSjypjADftm0KxmoEcZ5jlTxQRCq1yY-uUAF~s~tAfE4shpGjCC3bkB8zK07i2kQsX3vbWJxEmyOQXU21H4I2oDrk30cbrcJOqScm4tVSFB~Mg__&Key-Pair-Id=APKAJE5CCD6X7MP6PTEA){:height 24, :width 590}
##
## https://codepen.io/lobau/pen/ExyqJWV
## LATER A perfect use of text-overflow and white-space property of CSS
:PROPERTIES:
:background_color: #264c9b
:END:
You can create a box that showing the entire text when a user hovers over the box. ![2021_02_03_图片.png](https://cdn.logseq.com/%2F7aa8ab99-753a-4230-847b-43a1c3a3ef47c4bcb461-a20b-4b85-a8b6-7cb0951530c22021_02_03_%E5%9B%BE%E7%89%87.png?Expires=4765922314&Signature=WvT8pyerjrdDBVjaFbKCR7Ucgs8bn2CMBjlKf-1m57dc6AsO8wrk7Oj~YNsennTDdJIjpTq06K7THfUCRcE0YQOOJ6rtTHecG2DRb2SkYlHTOBzAMyPKemVzhCOB4dGDBkiwbqphlJnu5Y25JG~QiNypDvop3DUt0OophlhFn4Z~Fgmt7Y6gOWCUIOpuwlmqfCdiOQ6FzhtgOVrNgXA4YHz9CvkMsohlM4DGMuTbuDy~fwGbqZm1rKxIMVvY3rW5~BmnxdVvYUknzhoaICJviUolFTKCHo1m7A6reIxwUd1ZLKAYa6AOUhYEZGVl-U2kZjLnUlnDLQofDu5n4KGhNg__&Key-Pair-Id=APKAJE5CCD6X7MP6PTEA) ![2021_02_03_图片.png](https://cdn.logseq.com/%2F7aa8ab99-753a-4230-847b-43a1c3a3ef474dd52807-4618-4daf-8a0d-5aa419fa8b392021_02_03_%E5%9B%BE%E7%89%87.png?Expires=4765922252&Signature=Y3bsqCXK4XVqk6fiOCmkeJEIWv~5H3AkkmXBFmDeHsXxnWGvjBp6gLOuKmVYhrdKMvKe-x8CwxUoXRO4GYlb~G1aCtG~4n98KC5C7uIJmLFsFawusEorKDpGp3iUHnAIcIbAXUKTpabRNk~iHbakLO7urOvY2XWfIZRt7zRrAO8Wdi~WPlaxqRwOEZMze0rPgsqwEVzUtaLmiZpNNdCzcXS-OMtnm9zaDCI5vn8RIHtxqd-PbFK0y~MpXsFa1pdvF2MRj~fWZ6R5yZCaI3a2Jt4QH-2m-TXsL1yCF5gETY~dw5s7J6ds9UC4Caup~Petvr8hFvKsaxwqvLXWeloDvg__&Key-Pair-Id=APKAJE5CCD6X7MP6PTEA){:height 293, :width 292} ![2021_02_03_图片.png](https://cdn.logseq.com/%2F7aa8ab99-753a-4230-847b-43a1c3a3ef476ef3d5d2-d40b-4f25-a6a0-a2f49ea755da2021_02_03_%E5%9B%BE%E7%89%87.png?Expires=4765922230&Signature=i50k620x0xN1kCSS8R0Y2AUZgmfEYs6rZ3F-QGNDm0I87ovhXRMJvjGsa7khtOv-I8gp9rmm5TloO51XDypbKfGMwInT~cMXgWdVc8QM7t92GS14AJcoe1XF3Xwf41q~4CEcTwNUyhfdHDanyIK8VA8CfblFjFx6fww09pR5n69TQWrDA7uHleRDqHzTicoyHoOAVIIr6G-VIMwHJdOgeO1WsdYJ-1uatXOs7-zeV4Qiydsm6CUoEtOYYbUp-9M1e1y-NbGyR8sWtK9vMTDkgLRjO19dJ7f-IFStPnYvlVSvqYKzsWkBW2W9fdiPVtlkQVLgOiZzgGd6wT6XDdWU7Q__&Key-Pair-Id=APKAJE5CCD6X7MP6PTEA){:height 179, :width 279}
##
##
##
##
##
## BFC=== .bfc{ }
## ![2021_02_02_图片.png](https://cdn.logseq.com/%2F7aa8ab99-753a-4230-847b-43a1c3a3ef4794b87c5b-8bba-407f-ae6b-252164de70a42021_02_02_%E5%9B%BE%E7%89%87.png?Expires=4765844960&Signature=VDRUgfyFQ-ab2~0RYHrDhuuuIAnEroyCRfO-etbQKBdixu35l-Cyj1ZatU-3sF22D~jNXJIX3oiZrPnLR-eXQ0PreefhvJUFI1m7zQY3MBMv7S-tmWQsoNG-qCcNNx4XHe3kwtdCEdXuCabOvopnyHxWRIzWRrPMA-Dt-LEDD7P3anpJsgbcYcaa91-A393~KJa~bya-5f9eRtSMwiQmY8BB0rz~QGpeKtq7yqBzNqQI9evgpNnh6UkjF9j~x7RU1c~TEbqxP9OXfLSvOgShOncHq6rFFHLcUYqewQDNMrHOhUJqr1GHdGYeiB6hlFRo9u~HllUnJKht8jPKvTTEog__&Key-Pair-Id=APKAJE5CCD6X7MP6PTEA)
##
##
##
##
##
