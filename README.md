### 这些文件实现了linux中的pwd命令
##### 这个命令的实现参考了某位大佬的代码（但是找不到链接了......
#### 思路:
##### 在一个文件夹中判定当前的ino_t 和他上一层的 ino_t 如果相同说明达到了根，否则进入上一层目录，并根据这个文件夹的ino_t来查找他的文件名，并保存下来，之后输出
##### 为了实现这个思路，我们需要两个函数，一个根据filename 获得 ino_t，另一个根据ino_t 获得 filename
