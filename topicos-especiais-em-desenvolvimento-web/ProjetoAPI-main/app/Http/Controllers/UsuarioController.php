<?php

namespace App\Http\Controllers;

use Illuminate\Http\Request;
use GuzzleHttp\Client;

class UsuarioController extends Controller
{
    protected $client;

    public function __construct()
    {
        $this->client = new Client([
            'base_uri' => 'http://localhost:3000/',
            'headers' => [
                'Content-Type' => 'application/json',
            ],
        ]);
    }

    public function index()
    {
        try {
            $response = $this->client->get('usuarios');
            $usuarios = json_decode($response->getBody()->getContents(), true);
            return view('usuarios.index', compact('usuarios'));
        } catch (\Exception $e) {
            return redirect()->back()->with('error', 'Erro ao conectar ao JSON Server: ' . $e->getMessage());
        }
    }

    public function create()
    {
        return view('usuarios.create');
    }

    public function store(Request $request)
    {
        $request->validate([
            'nome' => 'required|string|max:255',
            'dataNascimento' => 'required|date',
            'email' => 'required|email|max:255',
            'cpf' => 'required|string|max:14',
            'fone' => 'required|string|max:15',
            'endereco_rua' => 'required|string|max:255',
            'endereco_cep' => 'required|string|max:9',
            'endereco_bairro' => 'required|string|max:255',
            'endereco_numero' => 'required|string|max:10',
            'endereco_cidade' => 'required|string|max:255',
            'endereco_estado' => 'required|string|max:2',
        ]);

        try {
            $response = $this->client->post('usuarios', [
                'json' => $request->all(),
            ]);
            return redirect()->route('usuarios.index')->with('success', 'Usuário criado com sucesso!');
        } catch (\Exception $e) {
            return redirect()->back()->with('error', 'Erro ao criar usuário: ' . $e->getMessage());
        }
    }
    public function show($id)
    {
        $response = $this->client->get("usuarios/{$id}");
        $usuario = json_decode($response->getBody()->getContents(), true);
        return view('usuarios.show', compact('usuario'));
    }

    public function edit($id)
    {
        $response = $this->client->get("usuarios/{$id}");
        $usuario = json_decode($response->getBody()->getContents(), true);
        return view('usuarios.edit', compact('usuario'));
    }

    public function update(Request $request, $id)
    {
        $response = $this->client->put("usuarios/{$id}", [
            'json' => $request->all(),
        ]);

        return redirect()->route('usuarios.index');
    }

    public function destroy($id)
    {
        $response = $this->client->delete("usuarios/{$id}");
        return redirect()->route('usuarios.index');
    }
}
