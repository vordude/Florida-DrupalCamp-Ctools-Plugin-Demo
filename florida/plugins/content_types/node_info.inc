<?php
/**
 * @file
 * Defines the top related content list panels pane.
 */


$plugin = array(
  'title' => t('Stuff you should know about this node'),
  'description' => t('Maybe not. But still.'),
  'category' => array(t('Super Sweet Content'), 0),
  'edit form' => 'florida_node_info_form',
  'render callback' => 'florida_node_info_render',
  'required context' => new ctools_context_required(t('Node'), 'node'),
  'defaults' => array(
    'vid' => 1,
    'pub_date' => 1,
    'node_type' => 1,
  ),
);

/**
 * Edit form.
 */
function florida_node_info_form($form, &$form_state) {
  $conf = $form_state['conf'];

  $form['vid'] = array(
    '#type' => 'checkbox',
    '#title' => t('Version ID'),
    '#default_value' => $conf['vid'],
  );
  $form['pub_date'] = array(
    '#type' => 'checkbox',
    '#title' => t('Published date'),
    '#default_value' => $conf['pub_date'],
  );
  $form['node_type'] = array(
    '#type' => 'checkbox',
    '#title' => t('Node type'),
    '#default_value' => $conf['node_type'],
  );
  return $form;
}

function florida_node_info_form_submit($form, &$form_state) {
  foreach (array_keys($form_state['plugin']['defaults']) as $key) {
    $form_state['conf'][$key] = $form_state['values'][$key];
  }
}

/**
 * Render callback.
 */
function florida_node_info_render($subtype, $conf, $args, $context) {
  $items = array();
  if ($conf['vid'] == 1) {
    $items[] = 'Node version ID: ' . check_plain($context->data->vid);
  }

  if ($conf['pub_date'] == 1) {
    $items[] = 'Node created date: ' . date('r', $context->data->created);
  }

  if ($conf['node_type'] == 1) {
    $items[] = 'Node type: ' . check_plain($context->data->type);
  }

  $variables = array(
    'items' => $items,
    'title' => '',
    'type' => 'ul',
    'attributes' => array(),
  );

  $block = new stdClass();
  $block->title = t('Node Info');
  $block->content = theme_item_list($variables);
  return $block;
}
