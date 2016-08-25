# Israfil
[![neutrino](https://img.shields.io/badge/Coded%20with-Neutrino%20IDE-brightgreen.svg?style=flat-square)](https://github.com/LER0ever/Neutrino)
![license](https://img.shields.io/badge/license-GPL%20V3-yellowgreen.svg?style=flat-square)
![israfil](https://img.shields.io/badge/LER0ever-Project%20Israfil-blue.svg?style=flat-square)
![AP](https://img.shields.io/badge/Angels-Parliament-ff69b4.svg?style=flat-square)  
### **|[关于](https://github.com/LER0ever/Israfil#关于这个项目)|[当前进度](https://github.com/LER0ever/Israfil#israfil-进度)|[开发日志](https://github.com/LER0ever/Israfil/issues/3)|[下载软件](https://github.com/LER0ever/Israfil#israfil下载)|[编译](https://github.com/LER0ever/Israfil#israfil编译)|[参与项目](https://github.com/LER0ever/Israfil#contributions-are-always-welcome)|[编译状态](https://github.com/LER0ever/Israfil#ci-status)|[版权](https://github.com/LER0ever/Israfil#copyright)|[协议](https://github.com/LER0ever/Israfil#license)|**
## LER0ever Project Israfil  
Provide Unified Music Service for users in China.  

**尽可能解决因为独家版权导致听/下一首歌需要下5\6个app以及多个音乐平台间歌曲歌单同步困难等问题。
Project Israfil通过实现各大音乐平台的API来提供统一的音乐服务，消除因版权导致的不方便.**

## IN EARLY DEVELOPMENT  
### 早期开发尚不可使用！！！
#### 我本人长期在墙外，有些网络相关问题由于海外访问限制无法及时发现，敬请谅解！  
Project Israfil只是本人的练笔之作，为了熟悉一下Go语言和Qt的开发，研究音乐平台协议只是顺手 ;)  
如本项目有侵权行为，请和我联系，我会立刻删除Repo  

## 关于这个项目
- 目前支持的平台: Linux, Windows, macOS, Android. (按照兼容性从高到低)，(iOS和FreeBSD理论上支持)
- IsrafilCore: (./IsrafilCore)纯C++11编写，提供音乐服务接口给IsrafilApp, 其他程序也可以自由调用此接口，**基本完成**  
- Israfil App quick: 尝试用 QML 作UI, **开发中**。  
- ~~_IsrafilCLI(暂停): (./IsrafilCLI)独立子项目，Go语言编写，Go-Pie插件机制，适合部署到服务器端提供统一的API 目前完成了网易和qq的搜索与下载地址获取_~~  

##### Github: [LER0ever/Israfil](https://github.com/LER0ever/Israfil)  
##### 国内镜像: [码云/LER/Israfil](http://git.oschina.net/ler/Israfil)

## Israfil 进度  
### **[开发日志及当前运行截图（持续更新）](https://github.com/LER0ever/Israfil/issues/3)**  
### 目前已经可以边开发边用它听歌了！
### **没有人点上面的链接，所以这儿强行插一张截图：**
左边为Windows Universal风格，右边为Material Design，可在P4设置中选择
![scnsht](http://i1.piimg.com/7134/2b3a78df28e9e4e9.png)
**由于项目在早期开发，您可以点右上[Watch](https://github.com/LER0ever/Israfil/subscription)接收项目开发动态提醒**
### [当前代码量统计](https://github.com/LER0ever/Israfil/blob/develop/doc/cloc.md)  
#### 任务列表:  
**加粗项代表正在开发的功能**
 - [ ] IsrafilApp
    - [ ] UI(QML)
       - [ ] **Qt5.7 QuickControls 2.0 UI界面**
       - [x] Qt MediaPlayer播放控制
       - [x] Material Design界面初步
       - [x] C++ 和 QML之间的caodan通讯 :(
 - [ ] IsrafilCore
    - [ ] 网易云音乐
       - [x] 获取图片和歌词地址
       - [x] 获取Mp3地址函数生效，并合并入search
       - [x] 完成网易搜索，整合进Universal Search，结果尚未排序
       - [ ] Universal 歌单整合
       - [x] 免登陆获取用户歌单
       - [ ] 跳进新API大坑
    - [ ] QQ音乐
       - [x] 获得歌曲歌词、专辑图片及下载链接(包括无损)
       - [ ] 歌单相关操作，包括合并为Universal歌单
       - [x] 整合音乐结果到Universal Search并加入Json
    - [ ] 天天动听
       - [x] 搜索歌曲获得歌曲详情json
       - [ ] Universal整合
    - [ ] Universal
       - [x] 封装QQ搜索至IsrafilCore
       - [x] SongList搜索结果重编码为Json供qml调用
       - [ ] **整合搜索**
    - [x] HTTPClient
       - [x] 自定义header发送GET请求
       - [x] 自定义header进行HTTP POST, 初步的网易搜索获得json
 - [ ] IsrafilCLI (Golang 独立项目，**暂停，推迟**)
    - [x] 网易&QQ：搜索歌曲获得详细信息以及获得下载链接
    - [ ] 基于termui的命令行界面
    - [ ] termui的editbox实现
    - [ ] 其他协议
 - [ ] 其他
    - [x] 持续集成
       - [x] 完成全自动化编译+上传二进制文件
       - [x] Travis改用Qt5.7编译
       - [ ] ~~添加自动配置cython及网易新API~~

## Israfil下载
### [LER0ever/Israfil-builds](https://github.com/LER0ever/Israfil-builds)  
- **直接点上面的链接↸↸↸，(前提是如果你完全不知道这整个页面在说什么的话，)上面的链接会带你去下载地址**
- 目前编译脚本不支持macOS，主要是Qt 5.7的问题。
- 注意，这个repo里的文件是本项目实时编译结果，**尚在早期开发，下下来也没什么用**  
- Releases里的格式为“操作系统 - 编译工具链 - 版本号 - 时间戳”，如macx-clang-0.1.0.0003-115355  
- 每次commit过后利用CI打Tag然后将Artifacts上传至Releases，Releases数量可能会较多，选择最近的二进制下载即可  
- Windows的二进制已经被WinDeployQt撸过了，Linux 和 OS X的没有自带Qt库，Linux请用包管理安装(大多数发行版都自带了)，Mac用户再说  

## Israfil编译
### 项目依赖
| 子项目           | 所有依赖项                             |
| :---:            | :---:                                  |
| IsrafilCore      | C++, libcurl                           |
| IsrafilApp/quick | C++, Qt5.7, IsrafilCore, 解码器       |
| IsrafilCLI       | Golang                                 |

### 准备环境
**由于用到了QtQuick.Controls 2.0 Qt最小要求版本为5.7**  
- Windows: Qt官网(qt.io)下载Qt For Windows并安装  
- Linux: 
```bash
sudo apt-add-repository --yes ppa:beineri/opt-qt57-trusty  
sudo apt-get -y update -qq  
sudo apt-get -y install qt57-meta-full
```
- OS X: ```brew install qt5``` (需要手动加入环境变量) 或者官网下载安装包安装  

### 编译
```bash
git clone https://github.com/LER0ever/Israfil
cd Israfil && mkdir build  
cd build && qmake ..
make
```
或者用Qt-Creator打开Israfil.pro，Release模式构建所有项目.  

## Contributions are always welcome
See [contribute.md](https://github.com/LER0ever/Israfil/blob/develop/doc/contribute.md)

## CI Status  
| Platform | Qt & Compiler       | Status                                                                                      |
| :---:    | :---:               | :---:                                                                                       |
| Linux    | 5.7 GCC     | ![traviscistatus](https://api.travis-ci.org/LER0ever/Israfil.svg)                           |
| OS X     | 5.6 Clang   | ![traviscistatus](https://api.travis-ci.org/LER0ever/Israfil.svg)                           |
| Windows  | 5.7 MinGW gcc       | ![appvayorstatus](https://ci.appveyor.com/api/projects/status/14ny9o50m4xb0c6g) |
| Android  | 5.5 gcc androideabi | ![shield](https://img.shields.io/badge/build-unknown-lightgrey.svg?style=flat-square)       |

## Copyright
| 3rd party           | License | Needed by        | in source            |
| :---:               | :---:   | :---:            | :---:                |
| Qt Project          | LGPL2   | IsrafilApp       | Universal Dependency |
| JosephP91/curlcpp   | MIT     | IsrafilCore      | Embedded in source   |
| JieweiWei/md5       | Apache  | IsrafilCore      | Embedded in source   |
| ddliu/go-httpclient | MIT     | HttpAPI          | Need manual go get   |

网易云音乐API参考了[网易云音乐API分析](https://github.com/yanunon/NeteaseCloudMusic/wiki/%E7%BD%91%E6%98%93%E4%BA%91%E9%9F%B3%E4%B9%90API%E5%88%86%E6%9E%90)  
网易云音乐新版/eapi正在研究中...  
Israfil中的歌曲和歌单版权归各大音乐平台所有  

### LICENSE
GNU GENERAL PUBLIC LICENSE V3  
See [Licence.md](https://github.com/LER0ever/Israfil/blob/develop/LICENSE.md) for details
