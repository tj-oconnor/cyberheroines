from flask import Flask, request, render_template, url_for,render_template_string

app = Flask(__name__)

@app.route("/", methods=["GET", "POST"])
def index():
    if request.method == "POST":
        name = request.form["name"]
        biography = request.form["biography"]
        template = '''<!DOCTYPE html><html lang="en"><head><meta charset="UTF-8"><meta name="viewport" content="width=device-width, initial-scale=1.0"><link rel="stylesheet" href="'''+url_for('static', filename='style.css')+'''">
        <title>CyberHeroines</title></head><body><div class="challenge-container"><div class="challenge-container"><img src='''+url_for('static', filename='heroine.png')+''' class="heroine"><div class="challenge-title">
        Received your nomination.</div><div class="challenge-description">"And I certainly want to have many many more women, and men, but especially women, have the experience of winning an award as I have done." - <p>Frances Allen, Keynote Address, 2008 Grace Hopper Celebration</p></div>
        <div class="output">Nomination received for: %s with bio:''' %name+ biography+'''</div>
        </div></body></html>''' 
        return render_template_string(template)

    return render_template("index.html")

if __name__ == "__main__":
    app.run(debug=False,host='0.0.0.0')

