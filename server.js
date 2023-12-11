const express = require('express');
const { spawn } = require('child_process');
const app = express();

app.use(express.static('public'));

app.get('/search', (req, res) => {
    const directoryPath = req.query.path;

    const command = 'C:\\Users\\ramon\\OneDrive\\Ambiente de Trabalho\\ANTÍ-VIRUS\\server\\search_files.exe'; 
    const args = [directoryPath]; 
    
    console.log('Recebendo requisição de busca...');
    console.log('Caminho do diretório:', directoryPath);
    console.log('Comando a ser executado:', command, args);
    
    const searchProcess = spawn(command, args);
    
    searchProcess.stdout.on('data', (data) => {
        const files = data.toString().split('\n').filter(file => file.trim() !== '');
        res.send(files);
    });
    
    searchProcess.stderr.on('data', (data) => {
        console.error(`Erro na execução do código C: ${data.toString()}`);
        res.status(500).send('Erro interno no servidor.');
    });

});

app.listen(3400, () => {
    console.log('Servidor rodando na porta 3400');
});
