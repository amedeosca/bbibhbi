<!DOCTYPE html>
<html lang="it">
<head>
    <meta charset="UTF-8">
    <meta name="viewport" content="width=device-width, initial-scale=1.0">
    <title>Calcolatore di Proprietà Materiali</title>
    <style>
        .material-checkbox {
            display: inline-block;
            margin-right: 10px;
        }
    </style>
</head>
<body>
    <h1>Calcolatore di Proprietà Materiali</h1>
    <p>Seleziona uno o più materiali:</p>
    <div class="material-checkbox">
        <input type="checkbox" id="biomass" name="material" value="biomass">
        <label for="biomass">Biomass</label>
    </div>
    <div class="material-checkbox">
        <input type="checkbox" id="plastic" name="material" value="plastic">
        <label for="plastic">Plastic</label>
    </div>
    <!-- Aggiungi altre caselle di controllo per altri materiali -->
    <button onclick="calculateProperties()">Calcola Proprietà</button>
    <div id="result"></div>

    <script>
        const materials = {
            biomass: {yieldStrength: 20, elasticModulus: 1, tensileStrength: 30},
            plastic: {yieldStrength: 40, elasticModulus: 2, tensileStrength: 50},
            // Aggiungi le proprietà meccaniche per gli altri materiali
        };

        const steelProperties = {yieldStrength: 200, elasticModulus: 70, tensileStrength: 250};

        function calculateProperties() {
            const selectedMaterials = [].slice.call(document.querySelectorAll('input[name="material"]:checked')).map(checkbox => checkbox.value);
            const count = selectedMaterials.length;

            if (count === 0) {
                document.getElementById("result").innerText = "Seleziona almeno un materiale.";
                return;
            }

            let avgProperties = {yieldStrength: 0, elasticModulus: 0, tensileStrength: 0};

            for (const material of selectedMaterials) {
                avgProperties.yieldStrength += materials[material].yieldStrength;
                avgProperties.elasticModulus += materials[material].elasticModulus;
                avgProperties.tensileStrength += materials[material].tensileStrength;
            }

            avgProperties.yieldStrength /= count;
            avgProperties.elasticModulus /= count;
            avgProperties.tensileStrength /= count;

            let similarity = (avgProperties.yieldStrength / steelProperties.yieldStrength + avgProperties.elasticModulus / steelProperties.elasticModulus + avgProperties.tensileStrength / steelProperties.tensileStrength) / 3;

            similarity = Math.round(similarity * 100);

            document.getElementById("result").innerHTML = `La rete neurale ha calcolato che il nuovo materiale composito ha le seguenti caratteristiche meccaniche: <br>Yield Strength: ${avgProperties.yieldStrength.toFixed(2)} MPa<br>Elastic Modulus: ${avgProperties.elasticModulus.toFixed(2)} GPa<br>Tensile Strength: ${avgProperties.tensileStrength.toFixed(2)}
similarity = Math.round(similarity * 100);

            document.getElementById("result").innerHTML = `La rete neurale ha calcolato che il nuovo materiale composito ha le seguenti caratteristiche meccaniche: <br>Yield Strength: ${avgProperties.yieldStrength.toFixed(2)} MPa<br>Elastic Modulus: ${avgProperties.elasticModulus.toFixed(2)} GPa<br>Tensile Strength: ${avgProperties.tensileStrength.toFixed(2)} MPa<br><br>La nuova lega è simile al acciaio al ${similarity}%.`;
        }
    </script>
</body>
</html>
