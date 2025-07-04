# 🚀 Multi-Language Monorepo with Turborepo

**7言語統合開発環境** - 過去・現在・未来の技術を一つのモノレポで管理

![Languages](https://img.shields.io/badge/Languages-7-brightgreen)
![Build](https://img.shields.io/badge/Build-Passing-success)
![Monorepo](https://img.shields.io/badge/Monorepo-Turborepo-blue)
![Platform](https://img.shields.io/badge/Platform-Windows%20%7C%20Linux%20%7C%20macOS-lightgrey)

## 🌟 概要

このプロジェクトは、**7つの異なるプログラミング言語**を統一されたモノレポ環境で管理する実験的なプロジェクトです。各言語の特性を活かしながら、現代的な開発ワークフローで統合管理することを実現しています。

## 🎯 言語構成

| 言語 | バージョン | 役割 | 特徴 | 実行形式 |
|------|------------|------|------|----------|
| 🔮 **Zig** | 0.14.0 | Next-gen System | 最新システム言語、日時ツール | CLI |
| 🔧 **C++** | C++17 | Classic System | 高性能システム分析 | CLI |
| 🦀 **Rust** | Latest | Modern System | 安全性重視、メモリ管理 | CLI |
| 🐹 **Go** | Latest | Network/Cloud | 並行処理、クラウドネイティブ | CLI |
| 🟣 **Kotlin** | 1.9.20 | JVM Modern | ヘルスチェック、JVM生態系 | CLI |
| 🐍 **Python** | 3.9+ | Data/AI | FastAPI、データ処理 | HTTP:8000 |
| ⚛️ **TypeScript** | Latest | Web Frontend | Next.js、モダンWeb | HTTP:3000 |

## 🏗️ アーキテクチャ

### **技術スタック**
- **モノレポ管理**: [Turborepo](https://turbo.build/)
- **パッケージ管理**: 各言語のネイティブツール（Cargo、Go Modules、Poetry、Gradle、npm）
- **ビルドシステム**: 言語固有（CMake、Gradle、Poetry、cargo、npm）
- **実行環境**: 統一コマンドでの並列実行

### **ディレクトリ構造**
```
turbo-rust-demo/
├── apps/
│   ├── zig-tools/          # 🔮 Zig - 次世代システムツール
│   ├── cpp-system/         # 🔧 C++ - クラシックシステム分析
│   ├── rust-api/           # 🦀 Rust - モダンシステム
│   ├── go-api/             # 🐹 Go - ネットワーク処理
│   ├── kotlin-api/         # 🟣 Kotlin - JVMヘルスチェック
│   ├── python-api/         # 🐍 Python - FastAPI
│   ├── web/                # ⚛️ Next.js - フロントエンド
│   └── docs/               # 📚 ドキュメント
├── packages/
│   ├── ui/                 # 共有UIコンポーネント
│   └── eslint-config/      # ESLint設定
├── package.json
├── turbo.json
└── README.md
```

## 🚀 クイックスタート

### **前提条件**
```bash
# 各言語の実行環境
- Node.js 18+
- Rust (rustup)
- Go 1.19+
- Python 3.9+
- Java 17+ (Kotlin用)
- CMake (C++用)
- Zig 0.14+
```

### **セットアップ**
```bash
# リポジトリクローン
git clone https://github.com/kazuma0606/multi-ranguage-monorepo.git

cd turbo-rust-demo

# 依存関係インストール
npm install

# 全言語同時実行
npm run dev
```

### **個別実行**
```bash
# 特定言語のみ実行
npx turbo dev --filter=zig-tools
npx turbo dev --filter=cpp-system
npx turbo dev --filter=python-api

# ビルド
npm run build

# テスト
npm run test
```

## 🎪 技術選択のストーリー

### **Phase 1: 基盤技術の模索**
当初は**Bazel**を使用した統合を試みましたが、以下の課題に直面：
- Windows環境での複雑な設定問題
- 各言語との統合時の設定の複雑さ
- 学習コストの高さ
- 実用性よりも複雑さが勝る状況

### **Phase 2: 実用性重視への転換**
**Turborepo**を採用することで課題を解決：
- ✅ **設定の簡素化**: 各言語のネイティブツールを活用
- ✅ **Windows完全対応**: 環境依存問題の解消
- ✅ **学習コストの最適化**: 実用的で習得しやすい
- ✅ **即戦力性**: 企業での実用性を重視

### **Phase 3: 言語選択の戦略**
7言語の選択理由：

#### **システムプログラミング領域**
- **Zig**: 最新技術への感度、未来指向
- **C++**: 企業での需要、高性能計算
- **Rust**: 安全性、モダンシステム開発

#### **アプリケーション開発領域**
- **Go**: クラウドネイティブ、並行処理
- **Kotlin**: JVM生態系、モダンOOP

#### **データ・Web領域**
- **Python**: AI/ML、データ処理
- **TypeScript**: モダンWeb、型安全性

## 🔧 各言語の実装内容

### **🔮 Zig Tools** (`apps/zig-tools/`)
```bash
# 次世代システムツール
- 日時計算・表示機能
- システム情報取得
- メモリ分析
- コンパイル時計算
- エラーハンドリング
```

### **🔧 C++ System** (`apps/cpp-system/`)
```bash
# クラシックシステム分析
- メモリ使用量分析
- STLアルゴリズム活用
- パフォーマンス測定
- Modern C++機能
- RAII/スマートポインタ
```

### **🦀 Rust API** (`apps/rust-api/`)
```bash
# モダンシステム実装
- 所有権システム
- 安全なメモリ管理
- パターンマッチング
- エラーハンドリング
```

### **🐹 Go API** (`apps/go-api/`)
```bash
# ネットワーク・並行処理
- Goroutines
- チャネル通信
- 高速コンパイル
- シンプルな文法
```

### **🟣 Kotlin API** (`apps/kotlin-api/`)
```bash
# JVMヘルスチェッカー
- システム監視
- メモリ使用量測定
- JVM情報取得
- Kotlinの関数型機能
```

### **🐍 Python API** (`apps/python-api/`)
```bash
# FastAPI Webサーバー
- RESTful API
- 自動OpenAPI生成
- 非同期処理
- Poetry依存関係管理
```

### **⚛️ Web Frontend** (`apps/web/`)
```bash
# Next.js Webアプリケーション
- React 18
- TypeScript
- Server Components
- 高速開発環境
```

## 🎯 パフォーマンス比較

| 言語 | 起動時間 | 実行速度 | メモリ効率 | 企業適用度 |
|------|----------|----------|------------|------------|
| **Zig** | ⚡⚡⚡ | ⚡⚡⚡ | ⚡⚡⚡ | 🔮 Future |
| **C++** | ⚡⚡⚡ | ⚡⚡⚡ | ⚡⚡⚡ | 🏢 High |
| **Rust** | ⚡⚡⚡ | ⚡⚡⚡ | ⚡⚡⚡ | 🏢 High |
| **Go** | ⚡⚡ | ⚡⚡ | ⚡⚡ | 🏢 Very High |
| **Kotlin** | ⚡ | ⚡⚡ | ⚡ | 🏢 High |
| **Python** | ⚡ | ⚡ | ⚡ | 🏢 Very High |
| **TypeScript** | ⚡⚡ | ⚡⚡ | ⚡⚡ | 🏢 Very High |

## 🚀 拡張性

### **新言語の追加**
本構成は以下の言語追加も容易：
- **Java**: エンタープライズ対応
- **C#**: Microsoft生態系
- **Swift**: Apple生態系
- **Haskell**: 関数型プログラミング
- **Lua**: 組み込みスクリプト

### **追加パッケージの統合**
```bash
# 新しいアプリケーション追加
mkdir apps/new-language
cd apps/new-language

# package.json作成
{
  "name": "new-language",
  "scripts": {
    "dev": "command-to-run",
    "build": "command-to-build",
    "test": "command-to-test"
  }
}

# Turborepoが自動で検出・統合
```

### **Docker統合**
```dockerfile
# 各言語をコンテナ化
FROM node:18-alpine
COPY apps/web ./
RUN npm install && npm run build

FROM rust:alpine
COPY apps/rust-api ./
RUN cargo build --release
```

## 📊 企業価値・採用観点

### **技術力アピール**
- ✅ **幅広い技術理解**: 7言語の特性把握
- ✅ **問題解決能力**: Bazel→Turborepo転換判断
- ✅ **実行力**: 実際に動作する成果物
- ✅ **最新技術感度**: Zigまで扱う先進性

### **実用性重視**
- ✅ **企業での即戦力**: 現実的な技術選択
- ✅ **チーム開発対応**: 統一されたワークフロー
- ✅ **運用性**: 保守しやすい構成

### **適用可能な企業・職種**
- **金融系**: C++高頻度取引、Pythonクオンツ
- **ゲーム系**: C++エンジン、TypeScriptUI
- **Web系**: Go/RustAPI、TypeScriptフロント
- **AI系**: PythonML、C++最適化
- **スタートアップ**: 全技術領域対応

## 🔄 CI/CD 設定

```yaml
# .github/workflows/ci.yml
name: Multi-Language CI
on: [push, pull_request]

jobs:
  test:
    runs-on: ubuntu-latest
    steps:
      - uses: actions/checkout@v3
      - uses: actions/setup-node@v3
      - name: Install dependencies
        run: npm install
      - name: Run tests
        run: npm run test
      - name: Build all
        run: npm run build
```

## 🤝 コントリビューション

1. Fork the repository
2. Create feature branch (`git checkout -b feature/amazing-feature`)
3. Commit changes (`git commit -m 'Add amazing feature'`)
4. Push to branch (`git push origin feature/amazing-feature`)
5. Open Pull Request

### **開発ガイドライン**
- 各言語のベストプラクティスに従う
- 統一されたコマンド体系を維持
- パフォーマンスとメンテナンス性を重視
- 実用性を最優先

## 📝 ライセンス

MIT License - 詳細は [LICENSE](LICENSE) を参照

## 🙏 謝辞

- [Turborepo](https://turbo.build/) - 素晴らしいモノレポツール
- 各言語コミュニティ - 優秀なツールチェーンの提供
- オープンソースコミュニティ - 継続的な技術革新

---

**「過去・現在・未来の技術を統合し、実用性を重視した現代的な開発環境」**

> 技術は複雑さではなく、問題解決のためにある