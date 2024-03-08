const String baseConfigPageHtml = R"=====(
<!DOCTYPE html>
<html lang='en'>
<head>
    <meta charset='UTF-8'>
    <meta content='width=device-width, initial-scale=1.0' name='viewport'>
    <title>基础配置页面</title>
    <style>
        body {
            font-family: Arial, sans-serif;
            margin: 20px;
            padding: 0;
            background-color: #f0f0f0;
        }

        form {
            max-width: 300px;
            margin: auto;
            padding: 20px;
            background-color: #ffffff;
            border-radius: 10px;
            box-shadow: 0 0 10px rgba(0, 0, 0, 0.1);
        }

        h2 {
            text-align: center;
            color: #333;
        }

        input[type=text], input[type=number] {
            width: 100%;
            padding: 10px;
            margin: 10px 0;
            border: 1px solid #ddd;
            border-radius: 5px;
            box-sizing: border-box;
        }

        input[type=submit] {
            width: 100%;
            background-color: #4CAF50;
            color: white;
            padding: 14px 20px;
            margin: 8px 0;
            border: none;
            border-radius: 5px;
            cursor: pointer;
        }

        input[type=submit]:hover {
            background-color: #45a049;
        }
    </style>
</head>
<body>
<h2>基础配置</h2>
<form method='POST' name='input' onsubmit="return submitForm()">
    <label>WiFi名称:
        <input name='wifi_ssid' required type='text' value='[WIFI_SSID]'>
    </label>
    <label>WiFi密码:
        <input name='wifi_password' type='text' value='[WIFI_PASSWORD]'>
    </label>
    <label>AP名称:
        <input name='ap_ssid' required type='text' value='[AP_SSID]'>
    </label>
    <label>AP密码:
        <input name='ap_password' type='text' value='[AP_PASSWORD]'>
    </label>
    <input type='submit' value='保存'>
</form>
</body>
<script>
    const password_placeholder = '空或8~16位英文字符';
    const password_pattern = '^$|^[ -~]{8,64}$';
    const passwordInputs = document.querySelectorAll('input[name*="password"]');
    const ssid_placeholder = '1~32个字符';
    const ssid_pattern = '^.{1,32}$';
    const ssidInputs = document.querySelectorAll('input[name*="ssid"]');
    passwordInputs.forEach(function (input) {
        input.placeholder = password_placeholder;
        input.title = password_placeholder;
        input.pattern = password_pattern;
    });
    ssidInputs.forEach(function (input) {
        input.placeholder = ssid_placeholder;
        input.title = ssid_placeholder;
        input.pattern = ssid_pattern;
    });

    function submitForm() {
        const formData = new FormData(document.forms['input']);
        fetch('/baseConfig', {method: 'POST', body: formData})
            .then(response => {
                console.log(response);
            })
        return false;
    }
</script>
</html>
)=====";

String getBaseConfigPageHtml(const String &wifi_ssid, const String &wifi_password, const String &ap_ssid, const String &ap_password) {
    String result = baseConfigPageHtml;
    result.replace("[WIFI_SSID]", wifi_ssid);
    result.replace("[WIFI_PASSWORD]", wifi_password);
    result.replace("[AP_SSID]", ap_ssid);
    result.replace("[AP_PASSWORD]", ap_password);
    return result;
}