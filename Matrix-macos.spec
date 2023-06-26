# -*- mode: python ; coding: utf-8 -*-
#from kivy.tools.packaging.pyinstaller_hooks import get_deps_all, hookspath, runtime_hooks, get_deps_minimal
from PyInstaller.utils.hooks import collect_data_files
import sys
import os.path

block_cipher = None

version_python = f'{sys.version[0]}.{sys.version_info[1]}'

if version_python == '3.10':
    pathex=['/opt/homebrew/lib/python3.10/site-packages/']
    target_arch='arm64'
else :
    if version_python == '3.9':
        pathex=['/Library/Frameworks/Python.framework/Versions/3.9/lib/python3.9/site-packages/']    
        target_arch='x86_64'

name=f'Matrix_{target_arch}.app'

a = Analysis(
    [
        'ascii12.py', 
    ],
    pathex=pathex,
    binaries=[],
    datas=[('matrix-macos.icns', '.'), ('matrix-linux.png', '.')],
    hiddenimports=[],
    hookspath=[],#hookspath(),
    hooksconfig={},
    runtime_hooks=[],#runtime_hooks(),
    excludes=[],
    win_no_prefer_redirects=False,
    win_private_assemblies=False,
    cipher=block_cipher,
    noarchive=False,
    #**get_deps_all(),
)
pyz = PYZ(a.pure, a.zipped_data, cipher=block_cipher)

exe = EXE(
    pyz,
    a.scripts,
    [],
    exclude_binaries=True,
    name='Matrix',
    debug=False,
    bootloader_ignore_signals=False,
    strip=False,
    upx=True,
    console=False,
    disable_windowed_traceback=True,
    argv_emulation=False,
    target_arch=target_arch,
    codesign_identity=None,
    entitlements_file=None,
    icon=['matrix-macos.icns'],
)

coll = COLLECT(
    exe,
    a.binaries,
    a.zipfiles,
    a.datas,
    strip=False,
    upx=True,
    upx_exclude=[],
    name='Matrix',
)
app = BUNDLE(
    coll,
    name=name,
    icon="matrix-macos.icns",
    bundle_identifier="com.matrix.bitscripts",
    info_plist={
        "CFBundleShortVersionString": "1.0.0",
        'NSPrincipalClass': 'NSApplication',
        'NSAppleScriptEnabled': False,
        'NSCameraUsageDescription': "This app requires camera access to capture your face photos to send you in Matrix.",
        'Application is background only': False,
        'AllowCacheDelete': True,
        'AllowPersonalCaching': True,
        "CFBundleDocumentTypes": [
            {
                'CFBundleTypeIconFile': 'matrix-macos.icns',
                "CFBundleTypeName": 'Package Icon',
                'CFBundleTypeRole': 'Editor',
                "CFBundleTypeOSTypes": ["ICON"],
            },
            {
                'CFBundleTypeIconFile': 'matrix-linux.png',
                "CFBundleTypeName": 'Image use in project',
                'CFBundleTypeRole': 'Editor',
                "CFBundleTypeOSTypes": ["IMAGE"],
            },
            {
                "CFBundleTypeExtensions": ["py", "pyw"],
                "CFBundleTypeName": "Python Scripts",
                "CFBundleTypeRole": "Editor",
                "CFBundleTypeOSTypes": ["TEXT"],
            },
            {
                "CFBundleTypeExtensions": ["txt"],
                "CFBundleTypeName": "Text",
                "CFBundleTypeRole": "Editor",
                "CFBundleTypeOSTypes": ["TEXT"],
            },
        ]
    },
)
