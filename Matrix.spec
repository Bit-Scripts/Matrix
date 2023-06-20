# -*- mode: python ; coding: utf-8 -*-


block_cipher = None

added_files = [
    ('I:\\Matrix\\matrix.ico', '.'),
    ('I:\\Matrix\\MatrixLogo.png', '.'),
    ('I:\\Matrix\\Matrix.PNG', '.'),
    ('I:\\Matrix\\mtx.ttf', '.')
]

a = Analysis(
    ['ascii17.py'],
    pathex=[],
    binaries=[('I:\\Matrix\\mtx.ttf', '.')],
    datas=added_files,
    hiddenimports=[],
    hookspath=[],
    hooksconfig={},
    runtime_hooks=[],
    excludes=[],
    win_no_prefer_redirects=False,
    win_private_assemblies=False,
    cipher=block_cipher,
    noarchive=False,
)

pyz = PYZ(a.pure, a.zipped_data, cipher=block_cipher)

pyi_splash = Splash('Matrix.PNG',
    binaries=a.binaries,
    datas=a.datas,
    text_pos=None,
    text_size=12,
    minify_script=True,
    always_on_top=True,
)


exe = EXE(
    pyz,
    a.scripts,
    a.binaries,
    a.zipfiles,
    a.datas,
    pyi_splash,
    pyi_splash.binaries,
    [],
    name='Matrix',
    debug=False,
    bootloader_ignore_signals=False,
    strip=False,
    upx=True,
    upx_exclude=[],
    runtime_tmpdir=None,
    console=False,
    disable_windowed_traceback=False,
    argv_emulation=False,
    target_arch=None,
    codesign_identity=None,
    entitlements_file=None,
    icon=['I:\\Matrix\\matrix.ico']
)
