<?php
/**
 * Processamento de uma chamada Ajax
 * $_GET deve conter a classe e, se necess�rio o m�todo
 * 
 */
include_once("framework/includes/autoload.inc");
include_once("framework/classes/classe_bancodados.inc");
include_once("framework/classes/classe_html.inc");
include_once("framework/classes/classe_formulario.inc");
include_once("framework/classes/classe_base.inc");
include_once("framework/includes/configbd.inc");

session_start();

if(!isset($_POST['classe'])||$_POST['classe']=='') {
	echo "Erro na Chamada Ajax " . var_Export($_POST,true);
} else {
	if(file_exists($_POST['arquivo_classe'])) {
		include_once($_POST['arquivo_classe']);
	}
	$_metodo = ($_POST['metodo']=="" ? 'buscaDadosAjax' : $_POST['metodo']);
	$_classe = new $_POST['classe']($_bd);
	$_classe->{$_metodo}();
}
?>