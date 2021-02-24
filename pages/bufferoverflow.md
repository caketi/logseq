---
title: bufferoverflow
---

## [https://d0nut.medium.com/week-13-introduction-to-buffer-overflows-5f15c0d5b5c1](https://d0nut.medium.com/week-13-introduction-to-buffer-overflows-5f15c0d5b5c1)
## https://mks.tw/[https://mks.tw/](https://mks.tw/)
## [https://anee.me/intro-to-pwn-65876c0cb558](https://anee.me/intro-to-pwn-65876c0cb558)
##
## ![image.png](/assets/pages_bufferoverflow_1614157634031_0.png)
## ![image.png](/assets/pages_bufferoverflow_1614157762043_0.png)
## ![image.png](/assets/pages_bufferoverflow_1614157865448_0.png)
##
## 大于6个参数，压入栈
## ![2021_02_07_图片.png](https://cdn.logseq.com/%2F7aa8ab99-753a-4230-847b-43a1c3a3ef47a8f69e3f-1f0b-4a3a-b395-83948993741e2021_02_07_%E5%9B%BE%E7%89%87.png?Expires=4766273523&Signature=e60hPn4~Ci9XBtn2EYl7MkB3NsQdDIfFFfJmA5uJWsYiex7sByhnaI1z~Qhio11GaH3TRe9cGu1FUElptcM4fLIWSzNEE38jzsFkeuQFWBxVpRfUIXl8FWLYLcIU0ZlGlu7FiYfATFCu9eYCVeGUfasOGuV6NHXvBQ06h7YclM-TEFYMpDmtiYa3T5evpySBOi-6Unbv25WQIchoFn52~qwqU-AamE~g02WwSxYhKvYb2NmNXzMdxKhUS7SYX~XL8O~2-OtyXZ12wCYjCxkNwG1zee2PNCnoL6AkVwDrdjDNkYvjPv4i78Iju3q-GvIaAIX9rwu3bOPEljOyDw0wXg__&Key-Pair-Id=APKAJE5CCD6X7MP6PTEA)
##
##
## esp呼叫ebp， 请求支援
## ![2021_02_07_图片.png](https://cdn.logseq.com/%2F7aa8ab99-753a-4230-847b-43a1c3a3ef47b88e14fe-4d4b-40d2-a269-4ba6eaaaf0542021_02_07_%E5%9B%BE%E7%89%87.png?Expires=4766273808&Signature=J4lHD1cnl5Zt7TvChqEE~9Iq-WUMuKkGryLdtDMmsDjtXUYKUbo0~OiiKLpjuMM7EIzylHz~U-3IlfKnHQEoVYIr69xK8WZ7M0O6EaIhZhzlauVDhM6rg4dbXM0bh9pYZF1Uvzm2hPAi7LQ3ZanHWSnZyKaP7jwKXzP5IYKXzbyWgd3HXH1i3k387sUe9jK10UxaOCyQ5kOLkeW5l03QfzboLpQVnUfB5K0j5kXZ0ZFfGyzxXA1-xfS5se4cGlfFF7aC4RGwHoGwNz~DW9ErEZyuE7XslU6MoxPMwSFmtk-cBegYva8xgmM50d8G611EXGZSjwRG6Vj8mDlD7fBOyQ__&Key-Pair-Id=APKAJE5CCD6X7MP6PTEA){:height 406, :width 626}
## ![2021_02_07_图片.png](https://cdn.logseq.com/%2F7aa8ab99-753a-4230-847b-43a1c3a3ef4714b5dce7-497a-43b6-b8cb-331790a4289d2021_02_07_%E5%9B%BE%E7%89%87.png?Expires=4766273351&Signature=MZ7jGRdTVKna--MUriUJ4uGUpCjfXeZyGzojCTJdGixymh2mi76Dx2IEDiVo7U5pO~GC9g9mxSGq6qDgtt3lA50PDJq13VsaDbXRJeEuGpvzMNWj1gZpHr9SgwKKLMiCrW1XqIS5gQmDn4WQ9sd8uRI5zNteS45oid6zLlVzOP-NcZE54wy4ZPxRxOEs0M2YG33FlOjjkSjGbbIWSQftwC0gpUZsBJMMpaE3md5l6d56RXQdeGMXWT7uBLrc~qCBpqqb54LF9XwoD-gwlxiYNesgJSX9xjJcnvVe1EG07bbharXm4EtPY7gpQReibrIaIy0Ewxp2OrDNLtxYUE~q5A__&Key-Pair-Id=APKAJE5CCD6X7MP6PTEA)
##
## ![2021_02_07_图片.png](https://cdn.logseq.com/%2F7aa8ab99-753a-4230-847b-43a1c3a3ef478143e3f0-712e-4983-bad9-a88ec5efc7e52021_02_07_%E5%9B%BE%E7%89%87.png?Expires=4766273035&Signature=Vn~Ull6X1GG9swZoJ4oUTkYii02HpVItXW56Qj22DmIBzhypiuE~GxwsKpfgyK8lOD6yLnJE02iOUdYcs55w50w9c2onjX2SD1NCS-JMW22--u3HUtxwpzZaZF4MppSBo5u65nMATotbZUMwQUSrqTSUfbfmsMH6kslni1seE6FZ-y8T58Ln7kyfim1xD1xktCALgtY2nEI9Zl0USpoBpRTn-3f6Y0aN5vJYovTLzU6ml5jYhE6XgUG7uPpwCB6B3f8SnGCXMsPfX3lsKHVu2gQlwxB9ZXSM76~LQg9SCyOx5I69JFD7lfrGW050-GsgaRMbgoe54FX3y3Y00FZ7lQ__&Key-Pair-Id=APKAJE5CCD6X7MP6PTEA)
## objdump -M intel =========转换为intel
## p64--8字节一个包
## p32--4字节一个包
## ![2021_02_07_图片.png](https://cdn.logseq.com/%2F7aa8ab99-753a-4230-847b-43a1c3a3ef47f4042c31-b50e-43ec-a0e0-32bd393519132021_02_07_%E5%9B%BE%E7%89%87.png?Expires=4766271756&Signature=T5LeE8y5l6k2LTYr4IgeKVEKUF-owRr7DKFNd8MNf~2vvBcluqIz5tXPLaJR40DZ8WJvLoZIYSE9oOmKwNH9k8GplTJrOXee--CNzHnHQhsdvDYeAJwBmg31xA8CPGJwbImjPUbO9eAojqviuBLxmeRKYmeeY2rQ5pJoa0n8LxyqMxz1BUvbS3NJ015bRRcGgm342~~0hml8--G7IIT2BvAdIDee8rRRTYTWKBYvqoMF2eS7HrKRcwFS-mw0lWIKshMqEUiAU4RUWpP29Hr77QF9t2NxzT7dkqM4F5otJ-v0x8y9L0eG6~jT6G4GMvIeHnt29c-6f8c9GFLE~ke5gQ__&Key-Pair-Id=APKAJE5CCD6X7MP6PTEA){:height 396, :width 411}
##
##
## ![2021_02_06_图片.png](https://cdn.logseq.com/%2F7aa8ab99-753a-4230-847b-43a1c3a3ef4751d60574-e4da-41cb-b50b-46afeaed7aa02021_02_06_%E5%9B%BE%E7%89%87.png?Expires=4766220695&Signature=RpjH9RXDCv3g5edmUs-Ir5BoCvD~ZOkqMy66pY5baQ4N51HExu1hBX7aQ0bX5E7OQf6QvHSc29L-WRgncDye78Mate-fbLeXLxueZuylyuXmXtpTS7MJXc03eeir5wF1AmQWAdEBZt1f~pn7-Tkib8OYalBt3ot6qhlQM6kfJ6Gi6An3~-ppc23goANNhfiDo6iPO7qUMT0xFrGCgWQuL7r~0DUknjSBFmMxaPRlruKHTliOCPTVCMznDKRg0DeR~U-H23BbXU~JwXl-NTtUPH0bSHIqZW4MmWXPpanggSfDXZ8dH47dDLJaD9xw7svPBz0zVLvGcd5auCJDKFxXLQ__&Key-Pair-Id=APKAJE5CCD6X7MP6PTEA){:height 113, :width 207}
## ![2021_02_06_图片.png](https://cdn.logseq.com/%2F7aa8ab99-753a-4230-847b-43a1c3a3ef476ca7a942-7c3e-4fb6-b211-fb2892be47612021_02_06_%E5%9B%BE%E7%89%87.png?Expires=4766220815&Signature=mGAt92WspZAU1A-FCfxfWbcA5HEjG676a5jAEVr0BcY7dM5r3ImtH2TfqnkHZob8dtebV1CD7x2Q-T~chNQgnUT7fAa6gmCwSzzlrqk9NdJhk7Sbg3ireb-r3c-liMpcuMU~p74tNYfry1-bctSfcuvKLmgKbKHv2ogDPIjIgw-nPU6DYnqUiudTCwnhci86yc-jbhyKdYMEQtUwHrXhzd7pqHCnYdhKeblR-tMnu9A-1v2KLLvRySpBcdgsQcFMxjuXeElQ6EzPIsqTUfaotLsh3g~ikF3q4ljVZiHtbEk0PPMhzXagi7WY9Hp4OiHre3mPHDedMKgq0EF8jy2tQA__&Key-Pair-Id=APKAJE5CCD6X7MP6PTEA){:height 130, :width 193}
## ![2021_02_06_图片.png](https://cdn.logseq.com/%2F7aa8ab99-753a-4230-847b-43a1c3a3ef470d54e029-6021-4d10-b847-77c48822f0ee2021_02_06_%E5%9B%BE%E7%89%87.png?Expires=4766220844&Signature=HRKJI1nwCka~OtGk~W7CAgrDBsLtOOsBL86qiTE0PIIswG~11FTn9lf-VLWuoBcb7RSfZhbL~sdhIT4sxmjBB9xeuFOGcxSi7duQxsEESFJ22TkwfEJrFu~YDGnEoHdeWRRwR9W33w5s4YXI7jWCOTdrE45BAj6HGVxK2thfOcInvV8rozGT5q2Zg09Jd~7VcKHenIueSQOrOCGDzcpmq6S-NBYhMLoYs0EbPf-cStglxTaqOX5MISuib~xuVNZ3WYz2Uw4862AMUMRT0zAwgztHssAzWVl3rnavZSECaUSMv39TIDYCxo~Dphl3LtiUPYgKa20r493vX9P6m~zEiA__&Key-Pair-Id=APKAJE5CCD6X7MP6PTEA)
##
##
##
##
##
