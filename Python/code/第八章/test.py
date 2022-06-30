ef func (a,b,c):
   p = ""
   if 16 < a or a < 2 or 16 < b or b < 2:
      return None
   else:
      if a != 10:
         count = 1
         for i in c:
            p += str(int(i)*(a)**(len(c)-count))
            count += 1
         p = int(p)
      else:
         p = int(c)
   j = [0, 1, 2, 3, 4, 5, 6, 7, 8, 9, 'A', 'b', 'C', 'D', 'E', 'F']
   k = []
   while True:
      s = p // b
      y = p % b  
      k = k + [y]
      if s == 0:
         break
      p = s
   k.reverse()
   o = ''
   for i in k:
      o += str(j[i])
   return o
