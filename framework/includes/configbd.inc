<?php
/**
 * Configurador para acesso ao Banco de Dados
 * Altere os valores de $_servidor, $_banco, $_usuario, $_senha e $_porta
 * 
 */

/**
 * @var string define o tipo do banco de dados, padr�o pgsql (op��o atual mysql)
 */
$_tipobd = 'pgsql';
/**
 * @var string define o endere�o do servidor do banco de dados
 */
$_servidor = "localhost";
/**
 * @var integer Porta de conex�o
 */
$_porta = 5433;
/**
 * @var string define o nome do banco de dados que desejamos conectar
 */
$_banco = "sistemaweb";
/**
 * @var string informa o nome do usu�rio
 */
$_usuario = "postgres";
/**
 * @var string Senha do usu�rio
 */
$_senha = "123456";

/**
 * Conecta com o Banco de dados e retorna uma instancia de bancodados
 */
$_bd = new $_tipobd();
$_bd->SetServidor($_servidor);
$_bd->SetPorta($_porta);
$_bd->SetBanco($_banco);
$_bd->SetUsuario($_usuario);
$_bd->SetSenha($_senha);
if($_bd->Conectar()===false) {
	die("<p style='color:red;font-weight:bold;text-align:center;'>Erro na conex�o com o Banco de Dados {$_bd->getUltimoErro()}</p>");
}
?>
