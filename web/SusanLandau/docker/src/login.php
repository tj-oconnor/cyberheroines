<?php
if ($_SERVER["REQUEST_METHOD"] == "POST") {
    if (isset($_POST['username']) && !empty($_POST['username'])) {
        header("Location: heroine.html");
    } else {
        header("Location: cyberheroine.html");
    }
    
    exit();
    $stmt->close();
    $conn->close();
}