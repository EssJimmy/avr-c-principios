Invoke-RestMethod -Uri https://get.scoop.sh | Invoke-Expression
scoop install mingw
scoop install gcc

$InstallLocation = "C:\MinGW\bin"
$persistedPath = [Environment]::GetEnvironmentVariable('Path', [EnvironmentVariableTarget]::Machine) -split ';'
   if ($persistedPath -notcontains $InstallLocation) {
       $persistedPath = $persistedPath + $InstallLocation | Where-Object { $_ }
       [Environment]::SetEnvironmentVariable('Path', $persistedPath -join ';', [EnvironmentVariableTarget]::Machine)
     }

    $envPaths = $env:Path -split ';'
    if ($envPaths -notcontains $InstallLocation) {
        $envPaths = $envPaths + $InstallLocation | Where-Object { $_ }
        $env:Path = $envPaths -join ';'
    }

Write-Output $env:PATH --split ";" | Select-String "MinGW"
scoop install avr-gcc
scoop install avrdude