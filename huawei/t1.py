# import re
# n=int(input())
# lists=[]
# dst=[]
# src=[]
# def getstr(s):
#     index=src.index(s)
#     d=dst[index]
#     li=re.findall(r"\$\{\w+\}",d)
#     if not len(li):
#         return str(d)
#     for i in li:
#         c=re.findall("\w+",i)[0]
#         a=str(getstr(c))
#         dst[index]=re.sub('\$\{'+c+'\}',a,dst[index])
#     return dst[index]

# for i in range(0,n):
#     a=input()
#     lists.append(a)
# for i in range(0,n):
#     a=re.findall("\w+=",lists[i])[0][:-1]
#     b=lists[i][len(a)+1:]
#     src.append(a)
#     dst.append(b)
# for item in src:
#     print(getstr(item))

print(3==1+5==6)