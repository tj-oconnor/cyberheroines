<?php
session_start();

$csrfToken = md5("hack this");
setcookie('csrf_token', $csrfToken, time() + 3600, '/'); // Set the cookie (not HttpOnly)

// Process the form submission
if ($_SERVER["REQUEST_METHOD"] == "POST") {
    // Validate the CSRF token
    $csrfToken = md5("cyberheroine");
    if ($_COOKIE['csrf_token'] === $csrfToken) {
        header("Location: assuredinfo.html");
        exit();
    } else {
        header("Location: sorry.html");
        exit();
    }
}
?>

<!DOCTYPE html>
<html lang="en">
<head>
<meta charset="UTF-8">
<meta name="viewport" content="width=device-width, initial-scale=1.0">
<title>On the Right Path</title>
<style>
  body {
    font-family: "Roboto Mono", monospace;
    background-color: black;
    color: hotpink;
    margin: 0;
    padding: 0;
    display: flex;
    justify-content: center;
    align-items: center;
    height: 100vh;
  }
  .container {
    text-align: center;
    padding: 20px;
    background-color: black;
    border-radius: 5px;
    box-shadow: 0 2px 4px rgba(0, 0, 0, 0.1);
  }
  img {
    max-width: 300px;
    height: auto;
  }
  .message {
    margin-top: 20px;
    font-size: 18px;
    color: white;
    line-height: 1.5;
  }
  .request-help {
    margin-top: 10px;
    font-size: 16px;
    color: white;
    text-decoration: none;
    transition: color 0.3s;
  }
  .request-help:hover {
    color: purple;
  }
  button {
    background-color: white;
    color: hotpink;
    border: none;
    padding: 10px 20px;
    border-radius: 3px;
    cursor: pointer;
  }
  button:hover {
    background-color: purple;
  }
</style>
</head>
<body>
    <div class="container">
        <img src="girl_finding_path.png" alt="Logo">
        <div class="message">
          You're on the right path. Keep going, and you'll find your treasure. Fingers crossed!
          <br>
          Request for help if needed, and keep exploring.
        </div>
        <form action="" method="post">
          <!-- Other form fields here -->
          <button type="submit">Request Help</button>
        </form>
      </div>
</body>
</html>

