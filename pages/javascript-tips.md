---
title: javascript-tips
---

## Did you know that you can assign object properties conditionally?

Instead of using if-statements and creating different objects, you can conditionally spread nested objects.

This prevents hasOwnProperty from listing an otherwise undefined property!
## ![2021_02_01_图片.png](https://cdn.logseq.com/%2F7aa8ab99-753a-4230-847b-43a1c3a3ef47089e5c09-a65f-4dca-b648-0ce83ac539c02021_02_01_%E5%9B%BE%E7%89%87.png?Expires=4765786889&Signature=H3jmi6TK30NAg9BE8Tv2grxMM-KFbTE7FwggBYwRt~sl8BAWF05Ag35Qcdzu4W4kL3CESP5XkqIytO6aYNbkjgrTQPP3OctIHlywaVN1wfzsipwbjijToTXyewj~O~SXahSWAcidbJs6dBy3IikwELHfelpe-PSclLgxufHn0T2uQs5Ii9B2sp3MT4k0y7aqOs2RtdxIrKM30X44gmjrtKSLPnsI8902F8NEp9IJ7Cgm7XVnDnY3PNCP-51qNrN~QICmjFpzFKuRQBgAbwYHnFu4QdIPNLTLJ84ult5ZytKXcPSF2f5fJahyvKoSOUR2tuhtFNaQ8H2i-Su6ujycYg__&Key-Pair-Id=APKAJE5CCD6X7MP6PTEA){:height 75, :width 112}
## ![2021_02_01_图片.png](https://cdn.logseq.com/%2F7aa8ab99-753a-4230-847b-43a1c3a3ef47f5690710-ea94-45b2-be17-cdaf3ec7bce52021_02_01_%E5%9B%BE%E7%89%87.png?Expires=4765787382&Signature=URSUOOdwgT-Zlr8UfX2Y1uJ9p62OtRcQCO2pWkRy2wOga-8MrkCL2NEBFHeTyaXgCXyq73hDD3Z-k4BSzVRslfBhtxwf0cRm5heTM3mKQoBlTnu5~-bC2Kg14Rz7GF7TkJDCA-ZS2u-8ljsM4Dx~uAV91AHz8aHDaxs7eDVEzsgs40JqUIRnvqYpjLJgXsdtZS6byANTirUxIgqPzqEcD~ll-FrndoJKiiGln9tDzqL8S3SC9UxZsUf1ddhsOjObF4Axia6Tq17~LCXLuSttk1AzsBqZZYnBlKnDfXa86TizxQ4EbASU-WPsVeuFS2Nvuxv0bNBB4cAlsW4IojnzjA__&Key-Pair-Id=APKAJE5CCD6X7MP6PTEA)
