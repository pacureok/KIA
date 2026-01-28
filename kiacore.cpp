static void GuardarMemoriaEterna(string dato)
{
    string log = $"[{DateTime.Now}] {dato}";
    // Cifrado simple para que no sea texto plano en el SSD
    byte[] bytesParaCifrar = System.Text.Encoding.UTF8.GetBytes(log);
    string datoCifrado = Convert.ToBase64String(bytesParaCifrar);
    
    File.AppendAllText(MemoriaPath, datoCifrado + Environment.NewLine);
    Console.WriteLine("[MEMORIA] Conocimiento cifrado y guardado en el SSD.");
}

static string LeerMemoriaEterna()
{
    if (!File.Exists(MemoriaPath)) return "Sin recuerdos previos.";
    string contenidoProtegido = File.ReadAllText(MemoriaPath);
    
    // Aquí el motor lo descifra para usarlo internamente
    try {
        var lineas = contenidoProtegido.Split(Environment.NewLine);
        string ultimoRecuerdo = lineas[lineas.Length - 2]; // Tomar el último
        byte[] bytesDescifrados = Convert.FromBase64String(ultimoRecuerdo);
        return System.Text.Encoding.UTF8.GetString(bytesDescifrados);
    } catch {
        return "Error al leer memoria protegida.";
    }
}
