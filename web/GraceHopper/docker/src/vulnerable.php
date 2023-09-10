<?php
$output = '';
if (isset($_GET['cmd'])) {
    $cmd = $_GET['cmd'];

    $blacklist = array('cat', 'ls', 'more', 'tac', 'nl', 'head', 'tail', 'awk', 'sed');
    $safe_to_run = true;
    foreach ($blacklist as $word) {
        if (strpos($cmd, $word) !== false) {
            $safe_to_run = false;
            $output = "You think it's that easy? Try harder!";
            break;
        }
    }

    if ($safe_to_run) {
        ob_start();
        system($cmd);
        $output = ob_get_clean();
    }
}
?>

<!DOCTYPE html>
<html lang="en">

<head>
    <meta charset="UTF-8">
    <meta name="viewport" content="width=device-width, initial-scale=1.0">
    <title> Commanding the Heroines </title>
    <style>
        body {
            font-family: 'Roboto Mono', monospace;
            background-color: black;
            color: white;
            display: flex;
            justify-content: center;
            align-items: center;
            height: 100vh;
            margin: 0;
            padding: 0;
        }

        .challenge-container {
            width: 60%;
            background-color: black;
            padding: 20px 40px;
            border-radius: 10px;
            box-shadow: 0 0 15px rgba(0, 0, 0, 0.2);
        }

        .challenge-title {
            font-size: 2.5em;
            margin-bottom: 20px;
            text-align: center;
            color: hotpink;
        }

        .challenge-description {
            font-size: 1.2em;
            margin-bottom: 20px;
            color: white;
        }

        .challenge-hint {
            font-size: 0.9em;
            background-color: #2C3A47;
            padding: 10px;
            border-radius: 5px;
            margin-bottom: 20px;
            color: white;
        }

        button {
            padding: 10px 15px;
            font-size: 1em;
            border: none;
            background-color: hotpink;
            color: white;
            border-radius: 5px;
            cursor: pointer;
            transition: background-color 0.3s;
        }

        button:hover {
            background-color: purple;
        }

        form {
            display: flex;
            align-items: center;
            justify-content: space-between;
        }

        input[type="text"] {
            flex: 1;
            padding: 10px;
            margin-right: 10px;
            border: none;
            border-radius: 5px;
            color: hotpink;
            background-color: white; /* Set the background color to white */
        }

        .output {
            background-color: #2C3A47;
            padding: 10px;
            border-radius: 5px;
            font-family: 'Courier New', Courier, monospace;
            color: white;
        }
    </style>
</head>

<body>
    <div class="challenge-container">
        <div class="challenge-title">
            Welcome Commander
        </div>
        <div class="challenge-description">
          A ship in port is safe, but that is not what ships are for. Sail out to sea and do new things. - Admiral Grace Hopper
        </div>
        <div class="challenge-hint">
            Hint: The file contains a SHA256 hash of the flag.
        </div>
        <form action="vulnerable.php" method="GET">
            <input type="text" name="cmd" placeholder="Enter your command here...">
            <button type="submit">Execute</button>
        </form>
        <br>
        <div class="output">
            <strong>Output:</strong><br>
            <pre><?php echo htmlspecialchars($output); ?></pre>
        </div>
    </div>
</body>

</html>

