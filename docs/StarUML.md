# 统一建模语言工具 [*StarUML*](http://staruml.io/)

## 注册码

请到官网 [*StarUML*](http://staruml.io/) 购买以支持正版。

<!--
  据《中华人民共和国著作权法（2010年2月26日第二次修正版）》第二十二条，
  下述行为及其影响仅可用于“为个人学习、研究或者欣赏”，不得用于其他用途。

  流下了贫穷的泪水 ( TдT)

  1. 从官网下载、安装客户端，并运行一次

  2. 安装 Node.js asar 包
     npm i (install) -g (--global) asar

  3. 切换到 StarUML 安装目录
     %LOCALAPPDATA%\Programs\StarURML\resources
     或者
     %PROGRAMFILES%\StarUML\resources
     后续操作可能需要管理员权限
     
     备份
     copy app.asar app.asar.bck
     
     解包
     asar extract app.asar app

  4. 修改鉴权代码
     文件：app\src\engine\license-manager.js
     函数：checkLicenseValidity ()
     修改为：
     
     checkLicenseValidity () {
       this.validate().then(() => {
         setStatus(this, true)
       }, () => {
         //setStatus(this, false)
         //UnregisteredDialog.showDialog()
         setStatus(this, true)
       })
     }

  5. 重新打包
     asar pack app app.asar

  6. 上述行为及其影响仅可用于“为个人学习、研究或者欣赏”，不得用于其他用途。
  -->
