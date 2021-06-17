# File System 
-  The number of dinode array keeps because when this don't keep asset sentence make fail in mkfs.c.  
-  The number of direct pointers minus 1.  
-  Double indirect is added in dinode and inode.  
-  Double indirect's the number of blocks is added in MAXFILE.
-  In bmap, double indirect block and indirect block are allocated.
-  In bmap, a[bn / NINDIRECT] is double indirect block.  
-  In bmap, a[bn % NINDIRECT] is indirect block.  
-  In itrunc, double indirect block and indirect block are freed.  