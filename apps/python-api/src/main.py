from fastapi import FastAPI
from datetime import datetime
import uvicorn

app = FastAPI(title="Python API", version="0.1.0")

@app.get("/")
async def hello():
    return {
        "message": "🐍 Hello from Python in Turborepo!",
        "framework": "FastAPI",
        "timestamp": datetime.now().isoformat(),
        "status": "working"
    }

@app.get("/health")
async def health():
    return {"status": "healthy", "service": "python-api"}

@app.get("/compute")
async def compute():
    # 簡単な計算
    numbers = [1, 2, 3, 4, 5]
    result = {
        "numbers": numbers,
        "sum": sum(numbers),
        "product": 1,
        "squares": [n**2 for n in numbers]
    }
    for n in numbers:
        result["product"] *= n
    
    return result

if __name__ == "__main__":
    print("🐍 Starting Python API with FastAPI...")
    uvicorn.run(app, host="0.0.0.0", port=8000)