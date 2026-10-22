# Put this in $PROFILE

function gpp {
    param (
        [Parameter(Position = 0, Mandatory = $true)]
        [string]$SourceFile,

        [Parameter(Position = 1)]
        [string]$Flags = "",

        [Parameter(Position = 2)]
        [string]$InputFile = ""
    )

    try {
        $fullSourcePath = Resolve-Path $SourceFile -ErrorAction Stop
    } catch {
        Write-Error "Source file not found: $SourceFile"
        return
    }

    $sourceDir = Split-Path $fullSourcePath
    $fileNameWithoutExt = [System.IO.Path]::GetFileNameWithoutExtension($fullSourcePath)
    $buildDir = Join-Path $sourceDir '.build'
    $outputPath = Join-Path $buildDir "$fileNameWithoutExt.exe"

    # Parse flags (default to "b" if nothing given)
    if (-not $Flags) {
        $Flags = "b"
    }

    $Flags = $Flags.ToLower()

    $doBuild = $Flags.Contains("b")
    $doRun   = $Flags.Contains("r")
    $useInput = $Flags.Contains("i")

    # If -r but no .exe, fallback to build
    if ($doRun -and -not (Test-Path $outputPath)) {
        Write-Host "Executable not found: $outputPath"
        Write-Host "Falling back to build..."
        $doBuild = $true
    }

    # Check input file if 'i' used
    if ($useInput) {
        if (-not $InputFile) {
            Write-Error "Flag 'i' provided but no input file given."
            return
        }
        if (-not (Test-Path $InputFile)) {
            Write-Error "Input file not found: $InputFile"
            return
        }
    }

    if ($doBuild) {
        if (-not (Test-Path $buildDir)) {
            New-Item -ItemType Directory -Path $buildDir | Out-Null
        }

        $sw = [System.Diagnostics.Stopwatch]::StartNew()
        g++ -std=c++20 -Wall -Wextra -Wshadow -Wduplicated-cond -Wlogical-op "`"$fullSourcePath`"" -o "`"$outputPath`""
        $sw.Stop()

        if ($LASTEXITCODE -eq 0) {
            $time = "{0:N2}" -f $sw.Elapsed.TotalSeconds
            Write-Host "Build succeeded: $outputPath"
            Write-Host "Time elapsed: $time seconds"
        } else {
            Write-Host "Build failed"
            return
        }
    }

    if ($doRun) {
        if (-not (Test-Path $outputPath)) {
            Write-Error "Executable not found after build: $outputPath"
            return
        }

        Write-Host "Running: $outputPath"

        if ($useInput) {
            Get-Content $InputFile | & $outputPath
        } else {
            & $outputPath
        }
    }
}
